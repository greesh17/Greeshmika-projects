from __future__ import print_function
import boto3
from boto3.dynamodb.conditions import Key
from boto3 import resource

def create_table(table_name):
    dynamodb_resource = resource('dynamodb',region_name='us-east-2')
    # to do
    # check the sample code https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/GettingStarted.Python.01.html
    # create the greetings table with attributes (gid, date, content).
    # return the table object
    mytable = dynamodb_resource.create_table(
      TableName=table_name,
      KeySchema=[
        {
            'AttributeName': 'gid',
            'KeyType': 'HASH'  #Partition key
        },

      ],
      AttributeDefinitions=[
        {
            'AttributeName': 'gid',
            'AttributeType': 'S'
        },



      ],
      ProvisionedThroughput={
        'ReadCapacityUnits': 10,
        'WriteCapacityUnits': 10
      }
    )

    mytable.meta.client.get_waiter('table_exists').wait(TableName='greetings')
    print(mytable.item_count)
    print("Table status:", mytable.table_status)

def get_table(table_name):
    "return the table object, when the table is already created"
    dynamodb_resource = resource('dynamodb',region_name='us-east-2')
    table = None
    try:
        table = dynamodb_resource.Table(table_name)
    except:
        print ("cannot get the table", table_name)
    finally:
        return table

def read_table_item(table, pk_name, pk_value):
    """
    table is the object returned by get_table
    Return item read by primary key.
    """
    tabledata = get_table(table)
    response = tabledata.get_item(Key={pk_name: pk_value})
    return response


def add_item(table, col_dict):
    """
    Add one item (row) to table. col_dict is a dictionary {col_name: value}.
    """
    tabledata = get_table(table)
    response = tabledata.put_item(Item=col_dict)
    return response


def delete_item(table, pk_name, pk_value):
    """
    Delete an item (row) in table from its primary key.
    """
    tabledata = get_table(table)
    response = tabledata.delete_item(Key={pk_name: pk_value})

    return response


if __name__ == '__main__':

    create_table("greetings")
    item1 = {'gid': '52222', 'date': '11/19/2019', 'content': 'first record'}
    item2 = {'gid': '53332', 'date': '11/20/2019', 'content': 'second record'}
    add_item("greetings",item1)
    print("first record added")
    add_item("greetings", item2)
    print("second record added")
    read_table_item("greetings",'gid','52222')
    print("Reading done successfully")
    delete_item("greetings",'gid','52222')
    print("Deleted successfully")
