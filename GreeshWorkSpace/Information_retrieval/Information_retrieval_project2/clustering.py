from sklearn.datasets import load_svmlight_file
feature_vectors, targets = load_svmlight_file("training_data_file.IDF")
from sklearn import metrics
from sklearn.cluster import KMeans, AgglomerativeClustering
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import chi2
import matplotlib.pyplot as plt
X_new1 = SelectKBest(chi2, k=1000).fit_transform(feature_vectors, targets)

kmeans_silhoutte_scores = []
kmeans_normalized_mutual_scores = []
krange = range(2,25)
for n in krange:

    kmeans_model = KMeans(n_clusters=n).fit(X_new1.toarray())
    clustering_labels = kmeans_model.labels_
    kmeans_silhoutte_scores.append(metrics.silhouette_score(X_new1.toarray(), clustering_labels
                                                            , metric='euclidean'))
    kmeans_normalized_mutual_scores.append(metrics.normalized_mutual_info_score(targets, clustering_labels))

single_linkage_silhoutte_scores = []
single_linkage_normalized_mutual_scores = []

for n in krange:
    
    single_linkage_model = AgglomerativeClustering(
            n_clusters=n, linkage='ward').fit(X_new1.toarray())
    clustering_labels = single_linkage_model.labels_
    single_linkage_silhoutte_scores.append(metrics.silhouette_score(X_new1.toarray(), clustering_labels
                                                                    , metric='euclidean'))
    single_linkage_normalized_mutual_scores.append(metrics.normalized_mutual_info_score(targets, clustering_labels))

plt.title('Kmeans')
plt.plot(krange,kmeans_silhoutte_scores)
plt.plot(krange,single_linkage_silhoutte_scores)
plt.xlabel('Number of Clusters')
plt.ylabel('Silhoutte Score')
plt.legend(['Kmeans','Single Linkage'])
plt.savefig('KMeans and Single Linkage - Silhoutte.jpg')
plt.show()
plt.title('Kmeans')
plt.plot(krange,kmeans_normalized_mutual_scores)
plt.plot(krange,single_linkage_normalized_mutual_scores)
plt.xlabel('Number of Clusters')
plt.ylabel('Mutual Information Score')
plt.title('Single Linkage')
plt.legend(['Kmeans','Single Linkage'])
plt.savefig('Kmeans and Single Linkage K - Mutual Information.jpg')
plt.show()