import boto3
import paramiko
import time
import socket
import sys

ec2 = boto3.resource('ec2')
client = boto3.client('ec2')
cp=paramiko.client.SSHClient()
cp.load_system_host_keys()


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
def status_monitor(newinst):
  while(True):
    for inst in newinstance:
        pemkey=paramiko.RSAKey.from_private_key_file("greeshkey.pem")
        #print(pemkey)
        cp.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        print("passed")
        print(ipaddress(inst.id))
        cp.connect(hostname=ipaddress(inst.id), username="ubuntu",pkey=pemkey)
        print("connected to ssh")
        stdin,stdout,stderr =cp.exec_command('top -bn1 | grep Cpu')
        print(inst.id ,'\t',stdout.readlines())
    time.sleep(10)

  return



if __name__ == '__main__':
    print("creatinginstances")
    newinstance = create_instance(2)
    instanceid = (i.id for i in newinstance)
    print_instanceid(instanceid)
    status_monitor(newinstance)

