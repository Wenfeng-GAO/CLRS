import sys
import time
import resource
from itertools import groupby
from collections import defaultdict


#set rescursion limit and stack size limit
sys.setrecursionlimit(10 ** 6)
resource.setrlimit(resource.RLIMIT_STACK, (2 ** 19, 2 ** 20))


class Track(object):
    """Keeps track of the current time, current source, component leader,
    finish time of each node and the explored nodes."""

    def __init__(self):
        self.current_time = 0
        self.current_source = None
        self.leader = {}
        self.finish_time = {}
        self.explored = set()


def dfs(graph_dict, node, track):
    """Inner loop explores all nodes in a SCC. Graph represented as a dict,
    {tail node: [head nodes]}. Depth first search runs recrusively and keeps
    track of the parameters"""

    # track.explored.add(node)
    # track.leader[node] = track.current_source
    # for head in graph_dict[node]:
    #     if head not in track.explored:
    #         dfs(graph_dict, head, track)
    # track.current_time += 1
    # track.finish_time[node] = track.current_time

    track.explored.add(node)
    track.leader[node] = track.current_source
    stack = [node]
    while stack:
            heads = [head for head in graph_dict[stack[-1]] if head not in
                            track.explored]
            if not heads:
                    n = stack.pop()
                    track.current_time += 1
                    track.finish_time[n] = track.current_time
            else:
                    for head in heads:
                            track.explored.add(head)
                            track.leader[head] = track.current_source
                            stack.append(head)


def dfs_loop(graph_dict, nodes, track):
    """Outter loop checks out all SCCs. Current source node changes when one
    SCC inner loop finishes."""

    for node in nodes:
        if node not in track.explored:
            track.current_source = node
            dfs(graph_dict, node, track)


def scc(graph, reverse_graph, nodes):
    """First runs dfs_loop on reversed graph with nodes in decreasing order,
    then runs dfs_loop on orignial graph with nodes in decreasing finish
    time order(obatined from firt run). Return a dict of {leader: SCC}."""

    out = defaultdict(list)
    track = Track()
    dfs_loop(graph, nodes, track)
    sorted_nodes = sorted(track.finish_time,
                          key=track.finish_time.get, reverse=True)
    track.current_time = 0
    track.current_source = None
    track.explored = set()
    dfs_loop(reverse_graph, sorted_nodes, track)
    for lead, vertex in groupby(sorted(track.leader, key=track.leader.get),
                                key=track.leader.get):
        out[lead] = list(vertex)
    return out

def graphsFromFile(path):
        graph = defaultdict(list)
        reverse_graph = defaultdict(list)
        with open(path, 'r') as file:
                for line in file:
                        tail, head = map(int, line.split())
                        graph[tail].append(head)
                        reverse_graph[head].append(tail)
        return graph, reverse_graph

# path = '/Users/Wenfeng/Downloads/scc.txt'
path = '/Users/Wenfeng/Downloads/_410e934e6553ac56409b2cb7096a44aa_SCC.txt'
graph, reverse_graph = graphsFromFile(path)

NUM = 875714
# NUM = 8
nodes = range(NUM, 0, -1)

out = scc(graph, reverse_graph, nodes)
top5 = [len(out[s]) for s in sorted(out, key=lambda k: len(out[k]),
        reverse=True)[:10]]
print top5
