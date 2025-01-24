from flask import Flask, request, render_template, redirect, url_for
import requests
import base64
import datetime
from minio import Minio
from minio.error import S3Error

app = Flask(__name__)
openfaas_url = "http://localhost:8080/function/face-blur"

minio_api = "localhost:9000"
access_key = "minioadmin"
secret_key = "minioadmin"

bucket_name = "image-bucket"

# Initialize MinIO client
minio_client = Minio(
    minio_api,
    access_key=access_key,
    secret_key=secret_key,
    secure=False
)


@app.route('/', methods=['GET'])
def index():
    return render_template('index.html', images_url=url_for('display_latest_image'))

@app.route('/upload', methods=['POST'])
def upload():
    if 'file' not in request.files:
        return redirect(request.url)
    file = request.files['file']
    if file:
        encoded_image = base64.b64encode(file.read()).decode('utf-8')
        response = requests.post(openfaas_url, data=encoded_image)
        alert_message = response.text
        print(alert_message)
        return """
        <script>
            alert('{}');
            window.location.href = '{}';
        </script>
        """.format(response, url_for('index'))
    return redirect(url_for('index'))

@app.route('/latest-image', methods=['GET'])
def display_latest_image():
    latest_blur_image = None
    latest_unblur_image = None
    latest_timestamp = None
    

    # Iterate through the blurred images in the folder
    for obj in minio_client.list_objects(bucket_name, prefix='Blurred/'):
        # Get the last modified timestamp of the object
        last_modified = obj.last_modified

        # Check if the current object is the latest object
        if latest_timestamp is None or last_modified > latest_timestamp:
            latest_blur_image = obj
            latest_timestamp = last_modified
    
    latest_timestamp = None
    # iterate through unburred images in the folder
    for obj in minio_client.list_objects(bucket_name, prefix='Unblurred/'):
        # Get the last modified timestamp of the object
        last_modified = obj.last_modified

        # Check if the current object is the latest object
        if latest_timestamp is None or last_modified > latest_timestamp:
            latest_unblur_image = obj
            latest_timestamp = last_modified

    if latest_blur_image:
        print(latest_blur_image.object_name)
        # Build the URL for displaying the latest image
        blur_image_url = f'http://{minio_api}/{bucket_name}/{latest_blur_image.object_name}'
        
    if latest_unblur_image:
        print(latest_unblur_image.object_name)
        # Build the URL for displaying the latest image
        unblur_image_url = f'http://{minio_api}/{bucket_name}/{latest_unblur_image.object_name}'
        
    

        # Render the template with the latest image URL
        return render_template('latest_image.html', blur_image_url=blur_image_url, unblur_image_url=unblur_image_url, return_url=url_for('index'))
    else:
        return 'No images found in the folder.'

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)