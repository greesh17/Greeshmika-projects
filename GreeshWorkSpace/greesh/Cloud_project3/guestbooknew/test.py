import requests
from requests.exceptions import HTTPError

for url in ['http://ec2-3-135-226-10.us-east-2.compute.amazonaws.com:5001/greetings']:
    try:
        response = requests.get(url)
        print(response)
        response.raise_for_status()

    except HTTPError as http_err:
        print('Http error occured:{http_err}')
    except Exception as err:
        print('other error occured:{err}')
    else:
        print('success!!')

