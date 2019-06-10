
'''
query processing

'''

import util
import norvig_spell
from index import InvertedIndex
import cranqry
import cran
import sys
import functools
import numpy
import collections

class QueryProcessor:
    preprocessed_query = {}
    result_vector = {}

    def __init__(self, query, index, collection):
        ''' index is the inverted index; collection is the document collection'''
        self.raw_query = query
        self.index = index
        self.docs = collection

    def preprocessing(self):
        ''' apply the same preprocessing steps used by indexing,
            also use the provided spelling corrector. Note that
            spelling corrector should be applied before stopword
            removal and stemming (why?)'''

        #ToDo: return a list of terms
        for x in self.raw_query:
            lower_case = util.query_lower(self.raw_query[x].text)
            lower_case = list(map(lambda y: norvig_spell.correction(y),lower_case)) #spelling correction is done before stemming and removing of stop words
            lower_case = list(map(lambda y: util.stemming(y), lower_case))
            for i in list(lower_case):
                if util.isStopWord(i):
                    lower_case.remove(i)
            QueryProcessor.preprocessed_query[x] = lower_case

    def findquery(self,query_id):
        for x in QueryProcessor.preprocessed_query:
            if x == query_id:
                return QueryProcessor.preprocessed_query.get(x)

    def booleanQuery(self,query_id):
        ''' boolean query processing; note that a query like "A B C" is transformed to "A AND B AND C" for retrieving posting lists and merge them'''
        #ToDo: return a list of docIDs
        query_results = []
        first_temp = self.findquery(query_id) #words are stored in list after preprocessing
        i = 0
        while i < len(first_temp):
            append_value = (list([0]), list(self.index.items.get(first_temp[i]).get('posting').keys()))[first_temp[i] in self.index.items]
            query_results.append(append_value)
            i = i+1
        #print(first_temp)
        return functools.reduce(numpy.intersect1d, query_results)

    def vectorQuery(self, k,query_id):
        ''' vector query processing, using the cosine similarity. '''
        #ToDo: return top k pairs of (docID, similarity), ranked by their cosine similarity with the query in the descending order
        # You can use term frequency or TFIDF to construct the vectors
        vector_query = {}
        document_vector = {}
        first_temp = self.findquery(query_id)
        for i in range(0,len(first_temp)):
            word_freq = (1 + math.log([first_temp.count(first_temp[i])][0], 10))   #getting word frequency
            idf_log = math.log(self.index.nDocs / (len(list(self.index.items.get(first_temp[i]).get('posting').keys()))), 10) # calculating IDF value
            value_append = (0,word_freq * idf_log)[first_temp[i] in self.index.items]
            vector_query[first_temp[i]] = value_append
        word_results = {}
        for document in self.docs:
            words = util.convert_word(document)
            for i in range(0,len(words)):
                if self.index.items.get(words[i]):
                    idf_log = math.log(self.index.nDocs / (len(list(self.index.items.get(words[i]).get('posting').keys()))),10)
                    term_freq = (1 + math.log(self.index.items[words[i]].get('posting').get(document.docID).get('tf'),10))
                    document_vector[words[i]] = (0,term_freq * idf_log)[words[i] in self.index.items]
            sqr_root = 0
            for x in document_vector:
                sqr_root += util.vector_mut(document_vector[x] , document_vector[x])
                sqr_root = numpy.reciprocal(numpy.sqrt(sqr_root))
            for y in document_vector:
                document_vector[y] *= sqr_root
            cosine = vector_query.copy()
            for u in vector_query:
                if u in document_vector:
                    cosine[u] = util.vector_mut(document_vector[u] , vector_query[u])  #cosine value of vector is calculated here
                else:
                    cosine[u] = 0
            sum_of_cosine = 0
            for i in cosine.values():
                sum_of_cosine += i
            word_results[document.docID] = sum_of_cosine
        return collections.Counter(word_results).most_common(k)

def test():
        ''' test your code thoroughly. put the testing cases here'''
        print('pass')


def query(index_file,algorithm,query_file, query_id):
    ''' the main query processing program, using QueryProcessor'''

    # ToDo: the commandline usage: "echo query_string | python query.py index_file processing_algorithm"
    # processing_algorithm: 0 for booleanQuery and 1 for vectorQuery
    # for booleanQuery, the program will print the total number of documents and the list of docuement IDs
    # for vectorQuery, the program will output the top 3 most similar documents
    query_file = cranqry.loadCranQry(query_file) # loading file
    index_items = InvertedIndex()
    index_items = index_items.load(index_file)
    cran_file = cran.CranFile('cran.all')
    query_verify = QueryProcessor(query_file, index_items, cran_file.docs)
    query_verify.preprocessing()
    results = None
    if algorithm == '0':                  # if algorithm is 0 it represents boolean model
        results = query_verify.booleanQuery(query_id)
    elif algorithm == '1':                # if algorithm is 1 it is vector model
        results = query_verify.vectorQuery(3,query_id)
    print(results)

if __name__ == '__main__':
    #test()

    query(str(sys.argv[1]), str(sys.argv[2]),str(sys.argv[3]),str(sys.argv[4]))
    #query('index_file','1','query.text','029')
