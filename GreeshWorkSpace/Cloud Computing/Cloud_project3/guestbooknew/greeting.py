from google.appengine.ext import ndb
from google.appengine.api import urlfetch
import urllib
import urllib2
import webapp2
import random


# [START greeting]

class Greeting(ndb.Model):
    """A main model for representing an individual Guestbook entry."""
    gid = ndb.IntegerProperty()
    content = ndb.StringProperty(indexed=False)
    date = ndb.DateTimeProperty(auto_now_add=True)
# [END greeting]


