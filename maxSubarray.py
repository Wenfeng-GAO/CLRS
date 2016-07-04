#!/usr/bin/env python

def maxSubArray(list, start, end):
        if start == end:
		return (start, start, list[start])

        mid = (end + start) / 2

	leftStart, leftEnd, leftValue = maxSubArray(list, start, mid)
	rightStart, rightEnd, rightValue = maxSubArray(list, mid+1, end)
	crossStart, crossEnd, crossValue = cross(list, start, mid, end)

	if leftValue >= rightValue and leftValue >= crossValue:
		return (leftStart, leftEnd, leftValue)
	elif rightValue >= leftValue and rightValue >= crossValue:
		return (rightStart, rightEnd, rightValue)
	else:
		return (crossStart, crossEnd, crossValue)

def cross(list, start, mid, end):
        s, leftIndex, leftValue = 0, mid, list[mid]
	for i in range(mid, start-1, -1):
		s += list[i]
		if s > leftValue:
			leftIndex, leftValue = i, s

	s, rightIndex, rightValue = 0, mid, list[mid]
	for i in range(mid, end+1):
		s += list[i]
		if s > rightValue:
			rightIndex, rightValue = i, s

	return start, end, leftValue + rightValue - list[mid]


list = [0,0,1,1,2]
start, end, value = maxSubArray(list, 0, len(list)-1)

print "From", start, "to", end, ":", value
