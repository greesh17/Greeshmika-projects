import boto3
import botocore

s3=boto3.resource('s3')
client=boto3.client('s3')
required_files=client.list_objects_v2(Bucket = 'wsu2017fall')

#print(required_files)

frombucket=s3.Bucket('wsu2017fall')
tobucket=s3.Bucket('greeshb')

for i in frombucket.objects.all():
    keys=i.key
    print("Keys in wsu2017fall: ",keys)
print("--------------------")

def reading_bucket(buckettoread,keysin):
      if (required_files.get('Contents', None) is not None):
         print("Reading files")
         for i in frombucket.objects.all():

          try:
            filedata=i.get()['Body'].read().decode()
            print(filedata)

          except:
            print("Directory is empty")
      else:
        print("Bucket is empty")
      return filedata
def copying_files():
 if(required_files.get('Contents',None)is not None):
  for f in required_files.get('Contents',None):
    for filekeys in frombucket.objects.all():
        sourcebucket={'Bucket':'wsu2017fall',
                     'Key':filekeys}
                   
        try:
          s3.meta.client.copy(sourcebucket,tobucket,filekeys)
       
        except:
          pass
  print("copied file successfully to {}".format(tobucket))
 else:
    print("Bucket is empty")

 return
for i in tobucket.objects.all():
    
    print("keys in my bucket: ",i.key)
print("--------------------")

if __name__ == '__main__':

    lines_data=reading_bucket(frombucket,keys)
    copying_files()
