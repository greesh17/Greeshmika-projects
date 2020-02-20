import boto3
import paramiko
import time
import socket
import sys

ec2 = boto3.resource('ec2')
client = boto3.client('ec2')
cp=paramiko.client.SSHClient()
cp.load_system_host_keys()
errorlog=[]

def create_instance(num_instances):
    return ec2.create_instances(ImageId='ami-0d5d9d301c853a04a',
                                KeyName="greeshkey",
                                InstanceType='t2.micro',
                                MinCount=1,
                                MaxCount=num_instances)
def print_instanceid(instanceid):
    instancewait = client.get_waiter('instance_running')
    instancecreated = []
    for id in instanceid:
        instancecreated.append(id)
        instancewait.wait(InstanceIds=[id])
    print(instancecreated)
    return

def ipaddress(instanceId):
   instances_created=client.describe_instances(InstanceIds =[instanceId])
   ip=instances_created['Reservations'][0]['Instances'][0] ['NetworkInterfaces'][0] ['Association']['PublicIp']
   return ip

def paramiko_monitor(newinstance):
   try:
    for inst in newinstance:
        pemkey=paramiko.RSAKey.from_private_key_file("greeshkey.pem")
        cp.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        print("key file is extracted")
        cp.connect(hostname=ipaddress(inst.id), username="ubuntu",pkey=pemkey)
        print("connected to ssh")
        stdin,stdout,stderr =cp.exec_command('sudo apt-get update && sudo apt-get install -y docker.io && sudo docker run -d -t ubuntu sh')
        print("Docker Installation started")
        print("Docker run command is successfull")
        for instaid in stdout:
            print(inst.id,'\t',ipaddress(inst.id),'\t',instaid)
   except:
       errorlog.append(inst.id)
       for i in errorlog:
           print(i)

   docker_monitor(newinstance)
   return

def docker_monitor(newinstance):
  while(True):
    for inst in newinstance:
        pemkey = paramiko.RSAKey.from_private_key_file("greeshkey.pem")
        cp.connect(hostname=ipaddress(inst.id), username="ubuntu", pkey=pemkey)
        print("connected to ssh")
        stdin, stdout, stderr = cp.exec_command('sudo docker ps | grep ubuntu')
        for docid in stdout:
           doc_container=docid.split()[0]
           stdin, stdout, stderr = cp.exec_command('sudo docker exec {} top -bn1 | grep Cpu'.format(doc_container))
        for k in stdout:
           print('{} \t {} \t {}'.format(inst.id,doc_container,k))
    time.sleep(10)

  return



if __name__ == '__main__':
    print("creatinginstances")
    newinstance = create_instance(2)
    instanceid = (i.id for i in newinstance)
    print_instanceid(instanceid)
    paramiko_monitor(newinstance)

