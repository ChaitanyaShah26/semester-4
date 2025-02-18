class Node:
    def __init__(self, name, cost=0, heuristic=0):
        self.name = name
        self.cost = cost
        self.heuristic = heuristic
        self.f = cost + heuristic  # Total cost

def a_star(start, goal, graph, heuristic):
    open_set = []
    closed_set = set()
    
    start_node = Node(start, 0, heuristic[start])
    open_set.append(start_node)
    
    came_from = {}
    g_score = {node: float('inf') for node in graph}
    g_score[start] = 0
    
    while open_set:
        # Find the node in open_set with the lowest f value
        current = min(open_set, key=lambda node: node.f)
        open_set.remove(current)
        
        if current.name == goal:
            return reconstruct_path(came_from, current.name), g_score[goal]  # Return path and cost
        
        closed_set.add(current.name)
        
        for neighbor, cost in graph[current.name].items():
            if neighbor in closed_set:
                continue
            
            tentative_g_score = g_score[current.name] + cost
            
            if tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current.name
                g_score[neighbor] = tentative_g_score
                f_score = tentative_g_score + heuristic[neighbor]
                
                # Check if the neighbor is already in the open set
                if not any(node.name == neighbor for node in open_set):
                    open_set.append(Node(neighbor, tentative_g_score, heuristic[neighbor]))
    
    return None, None  # Path not found

def reconstruct_path(came_from, current):
    total_path = [current]
    while current in came_from:
        current = came_from[current]
        total_path.append(current)
    return total_path[::-1]  # Return reversed path


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

path, total_cost = a_star(start, goal, graph, heuristic)

if path:
    print("Path found:", " -> ".join(path))
    print("Total cost:", total_cost)
else:
    print("No path found.")