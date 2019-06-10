from sklearn.datasets import load_svmlight_file
feature_vectors, targets = load_svmlight_file("training_data_file.IDF")
import matplotlib.pyplot as plt
from sklearn.naive_bayes import MultinomialNB , BernoulliNB
from sklearn.neighbors  import KNeighborsClassifier
from sklearn.model_selection import cross_val_score
from sklearn.svm  import SVC
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import chi2, mutual_info_classif


classifiers = ['MultinomialNB', 'BernoulliNB', 'KNeighborsClassifier', 'SVC']

for n,clf in enumerate([ MultinomialNB(), BernoulliNB(), KNeighborsClassifier(),SVC()]):

    chi2_scores = []
    mutual_info_scores = []
    for k in range(100, 5000, 100):

        X_new1 = SelectKBest(chi2, k=k).fit_transform(feature_vectors, targets)
        X_new2 = SelectKBest(mutual_info_classif, k=k).fit_transform(feature_vectors, targets)
        print(classifiers[n] + ' Chi Squared')
        scores = cross_val_score(clf, X_new1, targets, cv=5, scoring='f1_macro', verbose =0)
        chi2_scores.append(scores.mean())
        print("F1: %0.2f (+/- %0.2f)" % (scores.mean(), scores.std() * 2))


        print(classifiers[n] + ' Mutual Information')
        scores = cross_val_score(clf, X_new2, targets, cv=5, scoring='f1_macro', verbose =0)
        mutual_info_scores.append(scores.mean())
        print("F1: %0.2f (+/- %0.2f)" % (scores.mean(), scores.std() * 2))
        
    plt.title(classifiers[n] + ' Chi Squared')
    plt.plot(range(100, 5000, 100), chi2_scores)
    name = classifiers[n] + ' Chi Squared.jpg'
    plt.ylabel('F1_macro')
    plt.xlabel('K')
    plt.savefig(name)
    plt.show()
    plt.title(classifiers[n] + ' Mutual Information')
    plt.plot(range(100, 5000, 100), mutual_info_scores)
    name =classifiers[n] + ' Mutual Information.jpg'
    plt.ylabel('F1_macro')
    plt.xlabel('K')
    plt.savefig(name)
    plt.show()
