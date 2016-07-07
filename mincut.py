#!/usr/bin/env python

import random

def ajacencyListFromFile(path):
        list = []
        list.append([])

        with open(path) as file:
                for line in file:
                        vertex = []
                        for index in line.split():
                                vertex.append(int(index))
                        list.append(vertex)

        return list

# list = ajacencyListFromFile("c:/Users/ewenfga/Downloads/test.txt")
# print list

def combineVertex(list):
        indexA, indexB = 0, 0

        random.seed()
        vertexA = list[random.randint(1, len(list)-1)][0]
        
        for i in range(1, len(list)):
        	if list[i][0] == vertexA:
        		indexA = i
        		break

        random.seed()
        vertexB = list[indexA][random.randint(1, len(list[indexA])-1)]

        for i in range(1, len(list)):
        	if list[i][0] == vertexB:
        		indexB = i
        		break

        # print vertexA, vertexB, indexA, indexB

        while vertexA in list[indexB]:
        	list[indexB].remove(vertexA)

        for vertex in list[indexB]:
        	list[indexA].append(vertex)

        while vertexB in list[indexA]:
        	list[indexA].remove(vertexB)

        list.pop(indexB)
        for i in range(1, len(list)):
        	for index, vertex in enumerate(list[i]):
        		if vertex == vertexB:
        			list[i][index] = vertexA


# combineVertex(list)
# print list

def minCut(list):
	while len(list) > 3:
		combineVertex(list)
	# print list
	# print len(list[1]) - 1
	return len(list[1]) - 1

min_cut = 200
for i in range(100):
	list = ajacencyListFromFile("c:/Users/ewenfga/Downloads/kargerMinCut.txt")
	min_cut = min(minCut(list), min_cut)

print min_cut
