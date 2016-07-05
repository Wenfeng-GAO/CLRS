#!/usr/bin/env python

count = 0

def quickSort(A, start, end):
	global count

	if start < end:
		p = partition(A, start, end)
		count += end - start
		quickSort(A, start, p-1)
		quickSort(A, p+1, end)

def partition(A, start, end):
	mid = (start + end) / 2

	if A[start] < A[mid] < A[end] or A[end] < A[mid] < A[start]:
		A[start], A[mid] = A[mid], A[start]
	elif A[mid] < A[end] < A[start] or A[start] < A[end] < A[mid]:
		A[start], A[end] = A[end], A[start]

	i = start+1

	for j in range(i, end+1):
		if A[j] < A[start]:
			A[i], A[j] = A[j], A[i]
			i += 1

	A[start], A[i-1] = A[i-1], A[start]
	return i-1

def listFromFile(path):
	A = []

	with open (path, 'r') as file:
		for line in file:
			A.append(int(line))
	return A

A = listFromFile('c:/Users/ewenfga/Downloads/QuickSort.txt')
quickSort(A, 0, len(A)-1)

print A
print count