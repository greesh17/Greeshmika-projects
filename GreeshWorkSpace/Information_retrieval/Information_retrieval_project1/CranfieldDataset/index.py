
'''

Index structure:

    The Index class contains a list of IndexItems, stored in a dictionary type for easier access

    each IndexItem contains the term and a set of PostingItems

    each PostingItem contains a document ID and a list of positions that the term occurs

'''
from builtins import  open,list,len
import util
import re
from cran import  CranFile
from tokenize import tokenize,untokenize,NUMBER,STRING,NAME,OP
from nltk.stem import PorterStemmer
from nltk.tokenize import sent_tokenize,word_tokenize
from nltk.stem.snowball import SnowballStemmer
import json,codecs
import numpy as np
import math
import jsonpickle
import string
import sys

class Posting:
    def __init__(self, docID):
        self.docID = docID
        self.positions = []
        self.tf = 0;

    def append(self, pos):
        self.positions.append(pos)
        self.tf += 1;

    def sort(self):
        ''' sort positions'''
        self.positions.sort()  #sorting is done here

    def merge(self, positions):
        self.positions.extend(positions)
        self.term_freq(positions.length)

    def term_freq(self,length):
        ''' return the term frequency in the document'''
        # adding position length to tf to get exact tf in merging
        self.tf = self.tf + length
        return self.tf



class IndexItem:
    def __init__(self, term):
        self.term = term
        self.posting = {}  # postings are stored in a python dict for easier index building
        self.sorted_postings = []  # may sort them by docID for easier query processing

    def add(self, docid, pos):
        ''' add a posting'''
        if docid not in self.posting:
            self.posting[docid] = Posting(docid)
        self.posting[docid].append(pos)


    def sort(self):
        ''' sort by document ID for more efficient merging. For each document also sort the positions'''
        # ToDo


class InvertedIndex:

    def __init__(self):
        self.items = {} # list of IndexItems
        self.nDocs = 0  # the number of indexed documents


    def indexDoc(self, doc): # indexing a Document object
        ''' indexing a docuemnt, using the simple SPIMI algorithm, but no need to store blocks due to the small collection we are handling. Using save/load the whole index instead'''

        # ToDo: indexing only title and body; use some functions defined in util.py
        # (1) convert to lower cases,
        # (2) remove stopwords,
        # (3) stemming
        self.nDocs += 1
        lower_cases = util.tokenize_lower(doc)  #converting to lower cases
        doc_place = 1
        for i in range(0,len(lower_cases)):
            item = IndexItem(lower_cases[i])
            stemmed_value = util.stemming(lower_cases[i])   #stemming is done here by calling stemming function
            if stemmed_value not in self.items:
                item.add(doc.docID,doc_place)
                self.items[stemmed_value] = item

            else:
                self.items.get(stemmed_value).add(doc.docID, doc_place)
            doc_place = doc_place + len(lower_cases[i]) + 1;


    def sort(self):
        ''' sort all posting lists by docID'''
        # ToDo

    def find(self, term):
        return self.items[term]

    def save(self, filename):
        ''' save to disk'''
        # ToDo: using your preferred method to serialize/deserialize the index
        objects_encoded = jsonpickle.encode(self)
        sourcefile = open(filename, 'a')
        sourcefile.write(objects_encoded) #serializing index
        #sourcefile.close
        #print(objects_encoded)

    def load(self, filename):
        ''' load from disk'''
        # ToDo
        sourcefile = open(filename, "r")  #opening file to load index
        object_string = sourcefile.read()
        self = jsonpickle.decode(object_string)
        #print(object_string)
        return self

    def idf(self, term):
        ''' compute the inverted document frequency for a given term'''
        # ToDo: return the IDF of the term
    # more methods if needed


def test():
    ''' test your code thoroughly. put the testing cases here'''
    #testing stopwords remaoval
    if util.isStopWord('had'):  #returns whether it is true or false
       print('Pass')



def indexingCranfield(collectionname, indexfilename):
    # ToDo: indexing the Cranfield dataset and save the index to a file
    # command line usage: "python index.py cran.all indexs_file"
    # the index is saved to indexs_file
    cran_file = CranFile(collectionname)
    inverted_index = InvertedIndex()
    for doc in cran_file.docs:
        inverted_index.indexDoc(doc)
    ## remove stop word from items
    for keys in list(inverted_index.items):
        if util.isStopWord(keys):

            del inverted_index.items[keys]

    inverted_index.save(indexfilename)
    print("Indexing the cranfile done")

if __name__ == '__main__':
    # test()
    indexingCranfield(str(sys.argv[1]), str(sys.argv[2]))
    #indexingCranfield('cran.all', 'index_file')
