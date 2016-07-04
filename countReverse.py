#!/usr/bin/env python
import sys

def count(list):
	size = len(list)

	if size == 1:
		return (list, 0)

	leftList, leftNum = count(list[:size/2])
	rightList, rightNum = count(list[size/2:])
	midList, midNum = midCount(leftList, rightList)

	return (midList, leftNum + rightNum + midNum)

def midCount(leftList, rightList):
	max_value = sys.maxint
	
	leftList.append(max_value)
	rightList.append(max_value)

	midList = []
	midNum = 0
	i = 0
	j = 0

	for k in range(len(leftList) + len(rightList) - 2):
		if leftList[i] <= rightList[j]:
			midList.append(leftList[i])
			i += 1
		else:
			midList.append(rightList[j])
			j += 1
			midNum += len(leftList) - i - 1

	return (midList, midNum)

def listFromFile(path):
	list = []

	with open (path, 'r') as file:
		for line in file:
			list.append(int(line))

	return list

list = listFromFile("C:/Users/ewenfga/Downloads/IntegerArray.txt")
newList, num = count(list)

print newList
print num