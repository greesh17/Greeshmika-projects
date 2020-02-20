#KMeans clustering -Cloud computing Project 1 -2.1

used virtual box and cloudera ->os :redhat

steps for execution:
--------------------

1.Download centroid ,data.hdfs file and put them in HDFS location from local.
hdfs dfs -put /hom/cloudera/Downloads/centroids /user/greesh/centroids
hdfs dfs -put /hom/cloudera/Downloads/data.hdfs /user/data.hdfs

2.check if output is already existing and delete it if it exists
hdfs dfs -rm -r /user/greesh/output

3.After writing code in eclipse export it as java jar file.
click on java file ->export->java->jar->KMeans.jar

4.now execute java jar with help of hadoop jar with following command:
hadoop jar Kmeans.jar KMeans /user/greesh/centroids /user/data.hdfs /user/greesh/output