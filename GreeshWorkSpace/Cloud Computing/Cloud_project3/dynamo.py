from __future__ import print_function
import boto3
from boto3 import resource
from boto3.dynamodb.conditions import Key




def create_table(table_name):
   dynamodb_resource = resource('dynamodb',region_name='us-east-2',endpoint_url="http://localhost:8000", aws_access_key_id ='AKIAIPCD6YLRSLDTRBRQ', aws_secret_access_key='YuY+58G682xsAtPURpQd/YJE/eh6ElX7ynnnBpij')
    # to do
    # check the sample code https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/GettingStarted.Python.01.html
    # create the greetings table with attributes (gid, date, content).
    # return the table object
   table = dynamodb.create_table(
   TableName='Greetings',
   KeySchema=[
        {
            'AttributeName': 'gid',
            'KeyType': 'HASH'  #Partition key
        },
        {
            'AttributeName': 'date',
            'KeyType': 'RANGE'  #Sort key
        },
        {
            'AttributeName': 'content',
            'KeyType': 'RANGE'  #Partition key
        }
    ],
   AttributeDefinitions=[
        {
            'AttributeName': 'gid',
            'AttributeType': 'N'
        },
        {
            'AttributeName': 'date',
            'AttributeType': 'S'
        },
        {
            'AttributeName': 'content',
            'AttributeType': 'S'
        },

    ],
   ProvisionedThroughput={
        'ReadCapacityUnits': 10,
        'WriteCapacityUnits': 10
    }
)


print("Table status:", table.table_status)

def get_table(table_name):
    "return the table object, when the table is already created"
    dynamodb_resource = resource('dynamodb')
    table = None
    try:
        table = dynamodb_resource.Table(table_name)
    except:
        print "cannot get the table", table_name
    finally:
        return table

def read_table_item(table, pk_name, pk_value):
    """
    table is the object returned by get_table
    Return item read by primary key.
    """
    response = table.get_item(Key={pk_name: pk_value})

    return response


def add_item(table, col_dict):
    """
    Add one item (row) to table. col_dict is a dictionary {col_name: value}.
    """
    response = table.put_item(Item=col_dict)

    return response


def delete_item(table, pk_name, pk_value):
    """
    Delete an item (row) in table from its primary key.
    """
    response = table.delete_item(Key={pk_name: pk_value})

    return repsonse
