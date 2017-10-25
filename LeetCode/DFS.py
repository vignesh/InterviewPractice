#Source - http://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python/
def dfs(graph, start):
	explored = []
	stack = [start]
	while len(stack) > 0:
		node = stack.pop()
		if node not in explored:
			explored.append(node)
			neighbors = graph[node]
			for neighbor in neighbors:
				stack.append(neighbor)
	return explored

def dfsPointToPoint(graph, start, end):
	if start == end:
		return [start]
	explored = []
	stack = [[start]]
	while len(stack) > 0:
		path = stack.pop()
		node = path[-1]
		if node not in explored:
			explored.append(node)
			neighbors = graph[node]
			for neighbor in neighbors:
				newPath = list(path)
				newPath.append(neighbor)
				stack.append(newPath)
				if neighbor == end:
					return newPath
	#No path
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
	print dfs(graph, 'A')
	print dfs(g.edges, 'A')
	print dfsPointToPoint(graph, 'A', 'F')
	print dfsPointToPoint(g.edges, 'A', 'F')

if __name__ == "__main__":
	main()