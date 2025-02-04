# DFS Function for full traversal of the tree (recursive approach)
def dfs(tree, node, visited=None, result=None):
    if visited is None:
        visited = set()  # Initialize the visited set if it's the first call
    if result is None:
        result = []  # List to store the DFS traversal order
    
    # Mark the node as visited and add to the result list
    visited.add(node)
    result.append(node)  # Store the node
    
    # Recursively visit all the children (if any)
    for child in tree.get(node, []):
        if child not in visited:
            dfs(tree, child, visited, result)

    return result

# Function to input tree structure
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

# Perform DFS to traverse the tree
print("\nDFS traversal of the tree:")
result = dfs(tree, start)

# Join the result list with '->' and print it
print(" -> ".join(result))