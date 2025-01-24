import cv2
import os
import io
from minio import Minio
from minio.error import S3Error
import time
from PIL import Image, ImageFilter
import numpy as np
import base64

def blur_faces(image):
    # Convert the image to OpenCV format (numpy array)
    img_array = np.array(image)

    # Load the pre-trained face detection model
    face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

    # Convert the image to grayscale for face detection
    gray = cv2.cvtColor(img_array, cv2.COLOR_BGR2GRAY)

    # Detect faces in the image
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    # Blur the detected faces
    for (x, y, w, h) in faces:
        face = img_array[y:y+h, x:x+w]
        blurred_face = cv2.GaussianBlur(face, (99, 99), 30)
        img_array[y:y+h, x:x+w] = blurred_face

    # Convert the modified image back to PIL format
    modified_image = Image.fromarray(img_array)

    return modified_image, len(faces)


def handle(req):
    """ OpenFaaS function that blurs faces in an image and uploads it to MinIO. """
    
    # Read the MinIO API address from a file
    with open('function/minio_ip.txt', 'r') as file:
        minio_addresses = file.read().splitlines()
    minio_address = minio_addresses[0]
    minio_api = minio_address + ":9000"
    access_key = "minioadmin"
    secret_key = "minioadmin"

    # Initialize MinIO client
    minio_client = Minio(
        minio_api,
        access_key=access_key,
        secret_key=secret_key,
        secure=False
    )

    bucket_name = "image-bucket"
    try:
        # create bucket if doesn't exists
        found = minio_client.bucket_exists(bucket_name)
        if not found:
            print(f"Bucket {bucket_name} not found. Creating bucket with name {bucket_name}.")
            minio_client.make_bucket(bucket_name)
    
    except Exception as e:
        print(f"Error creating bucket - {str(e)}\nUsing {minio_api} as api." )
        return

    try:
        # using the current time for unique file name
        timestr = time.strftime("%Y%m%d-%H%M%S")
        original_file_name = "Unblurred/"+ timestr + "-Original.jpg"
        blurred_file_name = "Blurred/"+ timestr + "-Blurred.jpg"
        
        image_data = base64.b64decode(req)
        
        # Open the image using Pillow
        image = Image.open(io.BytesIO(image_data))
        
        # blur the face, convert to stream
        modified_image, num_faces = blur_faces(image)
        modified_image_stream = io.BytesIO()
        modified_image.save(modified_image_stream, format="JPEG")
        modified_image_stream.seek(0)

        
        # Upload the original image to MinIO
        minio_client.put_object(
            bucket_name,
            original_file_name,
            data=io.BytesIO(image_data),
            length=len(image_data),
            content_type='application/octet-stream'
        )
        
        print(f"File {original_file_name} uploaded successfully to bucket {bucket_name}.\n\n")
        
        # upload the modified image to MinIO
        minio_client.put_object(
            bucket_name,
            blurred_file_name,
            data=modified_image_stream,
            length=modified_image_stream.getbuffer().nbytes,
            content_type='application/octet-stream'
        )

        print(f"File {blurred_file_name} uploaded successfully to bucket {bucket_name}.\n\n")

    except S3Error as e:
        print("Error uploading file to MinIO - " + str(e))
        return

    except Exception as e:
        print("Error somewhere when uploading - "+str(e))
        return