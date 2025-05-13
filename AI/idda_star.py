class Node:
    def __init__(self, name, cost=0, heuristic=0):
        self.name = name
        self.cost = cost
        self.heuristic = heuristic
        self.f = cost + heuristic  # Total cost

def ida_star(start, goal, graph, heuristic):
    threshold = heuristic[start]
    path = [start]
    
    while True:
        print(f"\nCurrent threshold: {threshold}")
        temp = search(path, 0, threshold, goal, graph, heuristic)
        print(f"Path traversed in this iteration: {' -> '.join(path)}")
        
        if temp == "FOUND":
            return path
        if temp == float('inf'):
            return None  # No path found
        threshold = temp  # Update threshold for next iteration

def search(path, g, threshold, goal, graph, heuristic):
    current = path[-1]
    f = g + heuristic[current]
    
    if f > threshold:
        return f  # Return the f value if it's greater than the threshold
    
    if current == goal:
        return "FOUND"  # Goal found
    
    min_threshold = float('inf')
    
    for neighbor, cost in graph[current].items():
        if neighbor not in path:  # Avoid cycles
            path.append(neighbor)
            temp = search(path, g + cost, threshold, goal, graph, heuristic)
            if temp == "FOUND":
                return "FOUND"
            if temp < min_threshold:
                min_threshold = temp
            path.pop()  # Backtrack
    
    return min_threshold  # Return the minimum threshold found

# Input graph
graph = {}
heuristic = {}

n = int(input("Enter the number of nodes: "))

for _ in range(n):
    node = input("Enter node name: ")
    graph[node] = {}
    heuristic[node] = int(input(f"Enter heuristic value for node {node}: "))

m = int(input("Enter the number of edges: "))

for _ in range(m):
    edge = input("Enter edge (format: node1 node2 cost): ").split()
    node1, node2, cost = edge[0], edge[1], int(edge[2])
    graph[node1][node2] = cost
    graph[node2][node1] = cost  # Assuming undirected graph

start = input("Enter the start node: ")
goal = input("Enter the goal node: ")

path = ida_star(start, goal, graph, heuristic)

if path:
    print("\nFinal path found:", " -> ".join(path))
else:
    print("No path found.")