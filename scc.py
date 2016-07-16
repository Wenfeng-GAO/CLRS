#!/usr/env python

from collections import defaultdict

GREAT_NUM = 875714
# GREAT_NUM = 9

class Vertex:
	def __init__(self, order, master_node=0, explored=False):
		self.order = order
		self.master_node = master_node
		self.explored = explored

	def mark_explored(self):
		self.explored = True

nodes = [Vertex(n) for n in range(GREAT_NUM+1)]
count = 0
mn = 0

def adjFromFile(path):
	adj = [[] for x in range(GREAT_NUM+1)]

	with open(path, 'r') as file:
		for line in file:
			f, t = map(int, line.split())
			adj[f].append(t)

	return adj

def dfs(adj, s):
	global count
        global mn
	nodes[s].mark_explored()
        nodes[s].master_node = mn

	for n in adj[s]:
		if not nodes[n].explored:
			dfs(adj, n)

	count += 1
	nodes[s].order = count

# def dfs_stack(adj, s):
# 	global count
#         global mn
#         stack = [s]
#
#         while stack:
#                 n = stack[-1]
#                 nodes[n].mark_explored()
#                 nodes[n].master_node = mn
#                 print n
#
#                 for x in adj[n]:
#                         if not nodes[x].explored:
#                                 stack.append(x)
#
#                 count += 1
#                 node
#
def dfs_loop(adj):
        global mn
	for s in range(GREAT_NUM, 0, -1):
                mn = s
                if not nodes[s].explored:
                        dfs(adj, s)

def exchange(x):
        return nodes[x].order
        
def adjFromAdj(adj):
        dfs_loop(adj)
	adjRev = [[] for x in range(GREAT_NUM+1)]
        for index, ns in enumerate(adj):
                for n in ns:
                        adjRev[exchange(n)].append(exchange(index))
        return adjRev

def scc(adj):
        for n in nodes:
                n.explored = False
        dfs_loop(adj)

def top5():
        mns = defaultdict(int)
        for n in nodes:
               mns[n.master_node] += 1
        print sorted([v for v in mns.itervalues()], reverse=True)[:5]

adj = adjFromFile('/Users/Wenfeng/Downloads/scc.txt')
# dfs_stack(adj, 9)

adjRev = adjFromAdj(adj)
# scc(adjRev)
# top5()

# print [n.master_node for n in nodes]
