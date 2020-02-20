# Mapper.py hadoop streaming for cluster labeling

steps for execution:
--------------------

1. check if output folder already exists if so delete it
hdfs dfs -rm -r //user/greesh/kmeans_python/output

2.To run use below command
hadoop jar /usr/lib/hadoop-mapreduce/hadoop-streaming.jar -input /user/greesh/kmeans_python/inputfile/data.hdfs -output /user/greesh/kmeans_python/output -mapper "python mapper.py /user/greesh/centroids" -file /home/cloudera/python_source/Mapper.py

3.To check output please use below command
hdfs dfs -cat /user/greesh/kmeans_python/output/*