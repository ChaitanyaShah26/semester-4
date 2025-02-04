from collections import deque

# BFS Function for full traversal of the tree
def bfs(tree, start):
    # Initialize the queue with the start node
    queue = deque([start])  # Queue stores nodes
    visited = set()  # Set to track visited nodes
    
    # Perform BFS loop
    result = []  # List to store the BFS traversal order
    while queue:
        # Dequeue a node from the front of the queue
        node = queue.popleft()
        
        # If the node hasn't been visited, process it
        if node not in visited:
            result.append(node)  # Add node to the result list
            visited.add(node)
            
            # Enqueue all unvisited neighbors of the current node
            for neighbor in tree.get(node, []):
                if neighbor not in visited:
                    queue.append(neighbor)
    
    # Print the result list without trailing '->'
    print(" -> ".join(result))

# Function to input a tree from the user
def input_tree():
    tree = {}
    n = int(input("Enter the number of nodes in the tree: "))
    
    print("Enter the tree structure:")
    for _ in range(n):
        node = input("Enter node: ")
        children = input(f"Enter children of node {node} (comma separated): ").split(',')
        tree[node] = [child.strip() for child in children if child.strip()]
    
    return tree


# Input tree
tree = input_tree()

# Ask for start node (usually root)
start = input("Enter the start node (usually root): ")

# Perform BFS to traverse the tree
print("BFS traversal of the tree:")
bfs(tree, start)