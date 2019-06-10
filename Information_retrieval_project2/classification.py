from sklearn.datasets import load_svmlight_file
feature_vectors, targets = load_svmlight_file("training_data_file.IDF")

from sklearn.naive_bayes import MultinomialNB , BernoulliNB
from sklearn.neighbors  import KNeighborsClassifier
from sklearn.model_selection import cross_val_score
from sklearn.svm  import SVC

classifiers = ['MultinomialNB', 'BernoulliNB', 'KNeighborsClassifier', 'SVC']

for n,clf in enumerate([ MultinomialNB(), BernoulliNB(), KNeighborsClassifier(),SVC()]):
    
    print(classifiers[n])
    scores = cross_val_score(clf, feature_vectors, targets, cv=5, scoring='f1_macro')
    print("F1: %0.2f (+/- %0.2f)" % (scores.mean(), scores.std() * 2))
    scores = cross_val_score(clf, feature_vectors, targets, cv=5, scoring='precision_macro')
    print("Precision: %0.2f (+/- %0.2f)" % (scores.mean(), scores.std() * 2))
    scores = cross_val_score(clf, feature_vectors, targets, cv=5, scoring='recall_macro')
    print("Recall: %0.2f (+/- %0.2f)" % (scores.mean(), scores.std() * 2))