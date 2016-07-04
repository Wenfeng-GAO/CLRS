#!/usr/bin/env python

def maxSubArray(list):
	size = len(list)

	if size == 1:
		return (0, 0, list[0])

	leftStart, leftEnd, leftValue = maxSubArray(list[:size/2])
	rightStart, rightEnd, rightValue = maxSubArray(list[size/2:])
	crossStart, crossEnd, crossValue = cross(list)

	if leftValue >= rightValue and leftValue >= crossValue:
		return (leftStart, leftEnd, leftValue)
	elif rightValue >= leftValue and rightValue >= crossValue:
		return (rightStart, rightEnd, rightValue)
	else:
		return (crossStart, crossEnd, crossValue)

def cross(list):
	mid = len(list) / 2
	print "mid", mid
	print list

	start, end, s = mid, mid, 0
	
	leftValue = list[mid]
	for i in range(mid, -1, -1):
		s += list[i]
		print "s", s
		if s > leftValue:
			start, leftValue = i, s
			print start, leftValue

	s, rightValue = 0, list[mid]
	for i in range(mid, len(list)):
		s += list[i]
		if s > rightValue:
			end, rightValue = i, s

	return start, end, leftValue + rightValue - list[mid]


list = [0,0,1,1,2]
start, end, value = maxSubArray(list)

print "From", start, "to", end, ":", value