import boto3
import time
import sys

ec2 = boto3.resource('ec2')
client = boto3.client('ec2')
def create_instance(num_instances):

    return ec2.create_instances(ImageId='ami-0d5d9d301c853a04a',
                                InstanceType='t2.micro',
                                MinCount=1,
                                MaxCount=num_instances)
def print_instanceid(instanceid):
    instancewait = client.get_waiter('instance_running')
    instancecreated=[]
    for id in instanceid:
        instancecreated.append(id)
        instancewait.wait(InstanceIds=[id])
    print(instancecreated)
    return

if __name__ == '__main__':

    print("creatinginstances")
    newinstance=create_instance(3)
    instanceid=(i.id for i in newinstance)
    print_instanceid(instanceid)
    


