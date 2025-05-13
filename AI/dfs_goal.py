def dfs(tree, node, goal, visited=None, path=None):
    if visited is None:
        visited = set()  
    if path is None:
        path = []  
    
    visited.add(node)
    path.append(node) 
    
    if node == goal:
        print("Path to goal node:", " -> ".join(path))
        return path 

    for child in tree.get(node, []):
        if child not in visited:
            result = dfs(tree, child, goal, visited, path)
            if result is not None: 
                return result

    path.pop()
    return None

def input_tree():
    tree = {}
    n = int(input("Enter the number of nodes in the tree: "))
    
    print("Enter the tree structure:")
    for _ in range(n):
        node = input("Enter node: ")
        children = input(f"Enter children of node {node} (comma separated): ").split(',')
        tree[node] = [child.strip() for child in children if child.strip()]
    
    return tree

tree = input_tree()

start = input("Enter the start node (usually root): ")
goal = input("Enter the goal node: ")

print("\nDFS traversal to reach the goal node:")
dfs(tree, start, goal)