import abc
from greeting import Greeting
import json
import webapp2
from google.appengine.ext import ndb
from google.appengine.api import urlfetch

# the base class


class GreetingModel:

    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def getGreetings(self):
        pass
    @abc.abstractmethod
    def addGreeting(self, gid, date, content):
        pass


class GAEGreeting(GreetingModel):
    def __init__(self, guestbook_name):
        # constructor, initialize anything you need
        # to do
        self.guestbook_name = guestbook_name
        pass

    def getGreetings(self):
        # to do
        greetings_query = Greeting.query(ancestor=self.guestbook_key()).order(-Greeting.date)
        greetings_records= greetings_query.fetch(10)
        return  greetings_records

    def guestbook_key(self,):
        return ndb.Key('Guestbook',self.guestbook_name)

    def addGreeting(self, gid, date, content):
        # to do
        newgreeting = Greeting(parent = self.guestbook_key())
        newgreeting.gid = gid
        newgreeting.content = content
        newgreeting.put()
        return newgreeting.date

class DynamoGreeting(GreetingModel):
    def __init__(self, guestbook_name):
        # to do
        pass
    
    def getGreetings(self):
        # to do
        try:
            mylink ="http://ec2-3-135-226-10.us-east-2.compute.amazonaws.com:5001/greetings"
        
            greeting_records = urlfetch.fetch (mylink, method = urlfetch.GET)
            display= json.loads(greeting_records.content)
            print(display)
            for eachrecord in display:
                print(eachrecord)
        except urlfetch.Error:
            print("Sorry !!! Error in loading page")
        return display

    def addGreeting(self, gid, date, content):
           newdate=newdate=date.replace(" ","0")
           newlink = "http://ec2-3-135-226-10.us-east-2.compute.amazonaws.com:5001/addgreeting/"+str(gid)+"/"+str(newdate)+"/"+str(content)
           required_record=urlfetch.fetch(newlink,method=urlfetch.POST)
           print(required_record.content)


class UnifiedGreeting(GreetingModel):
    def __init__(self, guestbook_name):
        # create both GAE and Dynamo Models
        # the UnifiedGreeting model will be used by the GAE main program
        # to do
        pass

    def getGreetings(self):
        # pick one model to get all greetings
        # to do
        dynamo_record =DynamoGreeting('default_guestbook')
        greeting_record = dynamo_record.getGreetings()
        return greeting_record

    def addGreeting(self, gid, date, content):
        # append the new record to both models
        # to do

        gae_data= GAEGreeting('default_guestbook')
        record_new= gae_data.addGreeting(gid,date,content)
        dynamo_data = DynamoGreeting('default_guestbook')
        new_date = str(record_new)
        dynamo_data.addGreeting(gid,new_date,content)


