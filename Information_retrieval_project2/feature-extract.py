import nltk
nltk.download('punkt')
import pandas as pd
import sys

import os
from collections import defaultdict
from nltk.stem.snowball import EnglishStemmer  # Assuming we're working with English
 
class Index:
    """ Inverted index datastructure """
 
    def __init__(self, tokenizer, stemmer=None, stopwords=None):
        """
        tokenizer   -- NLTK compatible tokenizer function
        stemmer     -- NLTK compatible stemmer 
        stopwords   -- list of ignored words
        """
        self.tokenizer = tokenizer
        self.stemmer = stemmer
        self.index = defaultdict(list)
        self.documents = {}
        self.tf = defaultdict(list)
        self.__unique_id = 0
        if not stopwords:
            self.stopwords = set()
        else:
            self.stopwords = set(stopwords)
 
    def lookup(self, word):
        """
        Lookup a word in the index
        """
        word = word.lower()
        if self.stemmer:
            word = self.stemmer.stem(word)
 
        return [self.documents.get(id, None) for id in self.index.get(word)]
 
    def add(self, document):
        """
        Add a document string to the index
        """
        tokenized = [t.lower() for t in nltk.word_tokenize(document.read())]
        for token in tokenized:
            if token in self.stopwords:
                continue
 
            if self.stemmer:
                token = self.stemmer.stem(token)
 
            if self.__unique_id not in self.index[token]:
                self.index[token].append(self.__unique_id)
                self.tf[token].append(tokenized.count(token))
            
 
        self.documents[self.__unique_id] = document.name
        self.__unique_id += 1           
 
 

# Index for all documents
total_index = Index(nltk.word_tokenize, 
              EnglishStemmer(), 
              nltk.corpus.stopwords.words('english'))

# Create the inverted index for all documents 
for f in os.listdir(sys.argv[1]):
    for g in os.listdir(sys.argv[1]+'/'+f):
        try:
            file = open(sys.argv[1]+'/'+f+"/" +g, 'r')
            total_index.add(file)
        except:
            pass

# Create a dictionary to compute the inverse document frequencies
dic_idf = {}
for item in total_index.index.keys():
    try:
        dic_idf.update({item:1+len(total_index.lookup(item))})
    except:
        dic_idf.update({item:1})

feature_definition_file = [(idn, key) for idn, key in enumerate(total_index.index.keys())]

list_of_tuples = feature_definition_file
f = open(sys.argv[2]+'.txt', 'w')
for t in list_of_tuples:
    line = ' '.join(str(x) for x in t)
    f.write(line + '\n')
f.close()

# A map between feature ids and features
feature_definition_dic = {key:idn for idn, key in enumerate(total_index.index.keys())}

# Hardcoded newsgroup classfifications

dic  =  { 'comp.graphics':0,
          'comp.os.ms-windows.misc':0,
          'comp.sys.ibm.pc.hardware':0,
          'comp.sys.mac.hardware':0, 
          'comp.windows.x':0,
          'rec.autos':1
         , 'rec.motorcycles':1
         , 'rec.sport.baseball':1
         , 'rec.sport.hockey':1
         , 'sci.crypt':2
         , 'sci.electronics':2
         , 'sci.med':2
         , 'sci.space':2
         , 'misc.forsale':3
         , 'talk.politics.misc':4
         , 'talk.politics.guns':4
         , 'talk.politics.mideast':4
         , 'talk.religion.misc':5
         , 'alt.atheism':5 
         , 'soc.religion.christian':5}

f = open(sys.argv[3]+'.txt', 'w')
for i in dic:
    f.write(str('(') + str(i) + ',' + str(dic[i]) +")" + '\n')


data_tf = pd.DataFrame()
data_idf = pd.DataFrame()
data_tfidf = pd.DataFrame()


row = 0
for f in os.listdir(sys.argv[1]):
    print(f)
    for g in os.listdir(sys.argv[1]+'/'+f)[:10]:
        try:
            Individual_Index = Index(nltk.word_tokenize, 
                  EnglishStemmer(), 
                  nltk.corpus.stopwords.words('english'))

            
            file = open(sys.argv[1]+'/'+f+"/" +g, 'r')
            
            Individual_Index.add(file)
            


            for key in Individual_Index.index.keys():
                data_tf.at[row, 'Label'] = dic[f]
                data_tf.at[row, key]  = Individual_Index.tf[key][0]
                
                data_idf.at[row, 'Label'] = dic[f]
                data_idf.at[row, key]  = dic_idf[key]
                
                data_tfidf.at[row, 'Label'] = dic[f]
                data_tfidf.at[row, key]  = Individual_Index.tf[key][0]/dic_idf[key]
                
                
            row += 1
            Individual_Index = Index(nltk.word_tokenize, 
            EnglishStemmer(), 
            nltk.corpus.stopwords.words('english'))
            
        except:
            pass

data_tf = data_tf.rename(columns = {i:feature_definition_dic[i] for i in data_tf.columns if i != 'Label'})
data_idf = data_idf.rename(columns = {i:feature_definition_dic[i] for i in data_idf.columns if i != 'Label'})
data_tfidf = data_tfidf.rename(columns = {i:feature_definition_dic[i] for i in data_tfidf.columns if i != 'Label'})

data_tf.fillna(0,inplace=True)

data_tfidf.fillna(0, inplace=True)

data_idf.fillna(0, inplace=True)

from sklearn.datasets import dump_svmlight_file

e = data_tf["Label"]
d = data_tf[data_tf.columns.difference(['Label'])]

dump_svmlight_file(d,e,sys.argv[4]+'.TF')

e = data_idf["Label"]
d = data_idf[data_idf.columns.difference(['Label'])]

dump_svmlight_file(d,e,sys.argv[4]+'.IDF')

e = data_tfidf["Label"]
d = data_tfidf[data_tfidf.columns.difference(['Label'])]

dump_svmlight_file(d,e,sys.argv[4]+'.TFIDF')
