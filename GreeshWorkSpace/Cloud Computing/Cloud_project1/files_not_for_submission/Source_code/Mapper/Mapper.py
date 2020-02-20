import sys
import numpy as np
import os

def mapper(a,b,centroid_array):

    min_distance = []
    min_distance = np.append(euclidian_dist(centroid0[0], centroid0[1], a, b)) //distance between two centroids and data points are caluculated and stored in array 
    print(np.argmin(min_distance), "\t", a, b) // min distance of both is calculated and label is assigned


def read_centroids(fname):
    data = None
    with open(fname, "r") as fd: // opens file and reads data
        data = fd.read()
       
    return data


def split_centroids(centroids_raw):
    centroids = centroids_raw.split("\r\n")    // splits by line
    centroid0 = centroids[0].split("\t")[1].split(",") // splits line into words by delimiter , and puts first element into centroid 0
    centroid1 = centroids[1].split("\t")[1].split(",")
// splits line into words by delimiter , and puts second element into centroid 1

    return centroid0, centroid1


def euclidian_dist(centroid_a, centroid_b, a, b):
    centroid_a = float(centroid_a)
    centroid0_b = float(centroid_b)
    a = float(a)
    b = float(b)
    return ((centroid_a - a) ** 2 + (centroid_b - b) ** 2) ** 0.5 //distance between centroids and data is caluculated and returned


if __name__ == "__main__":
    for line in sys.stdin:
        data1, data2 = line.split("\t")[1].split("\n")[0].split(",") // data file is splitted by lines and words and first word assigned to data1 and second word to data2 
        centroid0, centroid1 = split_centroids(read_centroids(sys.argv[1]))
//both split_centroids and read_centroids functions are called
        centroid_array=[]
        centroid_array=np.append(centroid0,centroid1) resultant centroid0,centroid1 is stored in centroid_array
        mapper(data1,data2,centroid_array) // mapper function is called 
