from collections import deque

def bfs(tree, start, goal):
    queue = deque([(start, [start])])
    visited = set()  
    
    while queue:
        node, path = queue.popleft()
        if node not in visited:
            visited.add(node)

            if node == goal:
                print("Path to goal node:", " -> ".join(path))
                return path  

            for neighbor in tree.get(node, []):
                if neighbor not in visited:
                    queue.append((neighbor, path + [neighbor]))

    print("Goal node not found.")
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

print("BFS traversal to reach the goal node:")
bfs(tree, start, goal)