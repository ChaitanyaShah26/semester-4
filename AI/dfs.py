def dfs(tree, node, visited=None, result=None):
    if visited is None:
        visited = set()  
    if result is None:
        result = []  
    
    visited.add(node)
    result.append(node) 
    
    for child in tree.get(node, []):
        if child not in visited:
            dfs(tree, child, visited, result)

    return result

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

print("\nDFS traversal of the tree:")
result = dfs(tree, start)

print(" -> ".join(result))