#!/usr/bin/env python

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

list = ajacencyListFromFile("/Users/Wenfeng/Downloads/test.txt")
print list
print len(list)
print list[1][1]


def combineVertex(list):
        random.seed()
        vertexA = random.randint(1, len(list)-1)
        vertexB = list[vertexA][random.randint(1, len(list[vertexA]-1))]

        # for vertex in list[vertexA]:
                
