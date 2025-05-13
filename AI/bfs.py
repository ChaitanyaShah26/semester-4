from collections import deque

def bfs(tree, start):
    queue = deque([start])  
    visited = set()  
    
    result = [] 
    while queue:
        node = queue.popleft()
        if node not in visited:
            result.append(node)  
            visited.add(node)

            for neighbor in tree.get(node, []):
                if neighbor not in visited:
                    queue.append(neighbor)

    print(" -> ".join(result))

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

print("BFS traversal of the tree:")
bfs(tree, start)