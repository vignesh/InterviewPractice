"""
Source: https://pythoninwonderland.wordpress.com/2017/03/18/how-to-implement-breadth-first-search-in-python/
Always able to find solution if it exists.
High memory usage makes it unreasoable for real world problems (huge graphs), needs to keep track of all visited nodes.
Finds shortest paths for unweighted graphs (weight is 1 for eveyrthing)
"""

def bfs(graph, start):
	explored = []
	queue = [start]

	while len(queue) > 0:
		#get first element form queue
		node = queue.pop(0)
		#only check if node is not visited
		if node not in explored:
			#mark node as visited
			explored.append(node)
			#get all neigbors of current node
			neighbors = graph[node]
			for neighbor in neighbors:
				#add all neighbors in queue
				queue.append(neighbor)
	return explored

def bfsPointToPoint(graph, start, end):
	#start and end are same
	if start == end:
		return [start]

	explored = []
	queue = [[start]]

	while len(queue) > 0:
		path = queue.pop(0)
		#get last node from path
		node = path[-1]
		if node not in explored:
			explored.append(node)
			neighbors = graph[node]
			for neighbor in neighbors:
				newPath = list(path)
				newPath.append(neighbor)
				queue.append(newPath)
				if neighbor == end:
					return newPath
	#No path between start and end
	return []

#create graph from scrath
from collections import defaultdict
class Graph:
  def __init__(self):
    self.nodes = set()
    self.edges = defaultdict(list)
    self.distances = {}

  def add_node(self, value):
    self.nodes.add(value)

  def add_edge(self, from_node, to_node, distance):
    self.edges[from_node].append(to_node)
    self.edges[to_node].append(from_node)
    self.distances[(from_node, to_node)] = distance

def main():
	g = Graph()
	g.add_node('A')
	g.add_node('B')
	g.add_node('C')
	g.add_node('D')
	g.add_node('E')
	g.add_node('F')
	g.add_node('G')
	g.add_edge('A','B',1)
	g.add_edge('A','C',1)
	g.add_edge('A','E',1)
	g.add_edge('B','C',1)
	g.add_edge('B','D',1)
	g.add_edge('C','D',1)
	g.add_edge('E','F',1)
	g.add_edge('D','E',1)
	g.add_edge('F','C',1)
	#g and graph are the same
	graph = {'A': ['B', 'C','E'],
	             'B': ['A','C', 'D'],
	             'C': ['D'],
	             'D': ['C','E'],
	             'E': ['F','D'],
	             'F': ['C']}
	print bfs(g.edges, 'A')
	print bfs(graph, 'A')
	print bfsPointToPoint(graph,'A','F')
	print bfsPointToPoint(g.edges,'A','F')

if __name__ == "__main__":
	main()