#!/usr/env python

# GREAT_NUM = 875715
GREAT_NUM = 9

class Vertex:
	def __init__(self, order, master_node=None, explored=False):
		self.order = order
		self.master_node = master_node
		self.explored = explored

	def mark_explored(self):
		self.explored = True

nodes = [Vertex(n) for n in range(GREAT_NUM+1)]
count = 0

def adjFromFile(path):
	adj = [[] for x in range(GREAT_NUM+1)]

	with open(path, 'r') as file:
		for line in file:
			f, t = map(int, line.split())
			adj[f].append(t)

	return adj

def dfs(adj, s):
	# print s
	global count
	nodes[s].mark_explored()

	for n in adj[s]:
		if not nodes[n].explored:
			dfs(adj, n)

	count += 1
	nodes[s].order = count

def dfs_loop():
	for s in range(GREAT_NUM, 0, -1):
		dfs(adj, s)


adj = adjFromFile('c:/Users/ewenfga/Downloads/test.txt')
# dfs(adj, 9)
dfs_loop()

print [n.order for n in nodes]
