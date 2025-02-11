def get_tree_input():
    tree = {}
    num_nodes = int(input("Enter the number of nodes: "))
    
    print("Enter each node followed by its children (comma-separated):")
    for _ in range(num_nodes):
        parent = input("Enter node: ").strip()
        children_input = input(f"Enter children for node '{parent}' (comma-separated): ").strip()
        children = [child.strip() for child in children_input.split(',')] if children_input else []
        
        if parent in tree:
            tree[parent].extend(children)
        else:
            tree[parent] = children
            
    return tree
 
 
def depth_limited_search(tree, current_node, limit, depth, visited, path):
    if depth > limit:
        return
   
    visited.add(current_node)
    path.append(current_node)
 
    for neighbor in tree.get(current_node, []):
        if neighbor not in visited:
            depth_limited_search(tree, neighbor, limit, depth + 1, visited, path)
 
 
def iterative_deepening_search(tree, root):
    depth = 0
    levels = {}
    total_nodes = set(tree.keys()).union(*tree.values())
    visited_total = set()
 
    while len(visited_total) < len(total_nodes):
        visited = set()
        path = []
        depth_limited_search(tree, root, depth, 0, visited, path)
       
        if path:
            levels[depth] = path.copy()
            visited_total.update(visited)
       
        depth += 1
 
    print("\nTREE TRAVERSING")
    print(f"TOTAL LEVEL OF TREE = {depth - 1}")
    for lvl in range(depth):
        if lvl in levels:
            print(f"LEVEL {lvl}: {' '.join(levels[lvl])}")
 
 
# Input tree
tree = get_tree_input()

# Input source node
source = input("Enter source node: ").strip()

# Perform IDDFS traversal on the full tree
iterative_deepening_search(tree, source)

print("\nIDDFS traversal completed.")