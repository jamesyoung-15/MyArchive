import os
import io
from minio import Minio
from minio.error import S3Error
import time

bucket_name = "image-bucket"

# Initialize MinIO client
client = Minio(
    "localhost:9000",
    access_key='minioadmin',
    secret_key='minioadmin',
    secure=False
)

try:
    # The file to upload, change this path if needed
    source_file = "./test.txt"

    # The destination bucket and filename on the MinIO server
    destination_file = "my-test-file.txt"

    # Make the bucket if it doesn't exist.
    found = client.bucket_exists(bucket_name)
    if not found:
        client.make_bucket(bucket_name)
        print("Created bucket", bucket_name)
    else:
        print("Bucket", bucket_name, "already exists")

    # Upload the file, renaming it in the process
    client.fput_object(
        bucket_name, destination_file, source_file,
    )
    print(
        source_file, "successfully uploaded as object",
        destination_file, "to bucket", bucket_name,
    )




except S3Error as e:
    print(str(e) + " - Error uploading file to MinIO.")


except Exception as e:
    print(str(e) + " - Error somewhere.")
