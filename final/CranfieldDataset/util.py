
'''
   utility functions for processing terms

    shared by both indexing and query processing
'''

import re
from nltk.stem import PorterStemmer
from nltk.tokenize import sent_tokenize,word_tokenize
import numpy
stop_word_list = []
sourcefile = open('stopwords', 'r')
for text_key in sourcefile:
    stop_word_list.append(text_key.strip())
porter_stemmer = PorterStemmer()
#print(len(stop_word_list))
def isStopWord(word):
    ''' using the NLTK functions, return true/false'''
    if word in stop_word_list:  #finding stopwords in the document
        #print(word)
        return True
    else:
        return False
    # ToDo


def stemming(word):
    ''' return the stem, using a NLTK stemmer. check the project description for installing and using it'''
    stemmed_word =porter_stemmer.stem(word)
    return stemmed_word
    # ToDo


def tokenize_lower(doc):
    #lower case
    tokenbody = word_tokenize(doc.body)
    tokentitle = word_tokenize(doc.title)
    tokens = tokenbody + tokentitle
    lower = [key.lower() for key in tokens]
    return lower

def query_lower(text):
    token = word_tokenize(text)
    lower = [key.lower() for key in token]
    return lower

def convert_word(doc):
    words = tokenize_lower(doc)
    for word in list(words):
        if isStopWord(word):
            words.remove(word)
    for i in range(0, len(words)):
        words[i] = stemming(words[i])
    return words

def vector_mut(x,y):
    return x*y
