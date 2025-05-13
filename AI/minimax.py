def input_tree():
    tree = {}
    n = int(input("Enter the number of nodes in the tree: "))
    
    print("Enter the tree structure:")
    for _ in range(n):
        node = input("Enter node label: ")
        children = input(f"Enter children of node '{node}' (comma separated, leave empty if leaf): ").split(',')
        tree[node] = [child.strip() for child in children if child.strip()]
    
    return tree

# Function to assign values to leaf nodes
def assign_leaf_values(tree):
    values = {}
    print("\nEnter values for leaf nodes:")
    for node in tree:
        if not tree[node]:  # If the node has no children
            val = int(input(f"Value for leaf node '{node}': "))
            values[node] = val
    return values

# Minimax function with path tracking
def min_max(node, is_maximizing):
    if node not in tree or not tree[node]:  # Base case: leaf node
        return values[node], [node]

    if is_maximizing:
        best_value = float('-inf')
        best_path = []
        for child in tree[node]:
            val, path = min_max(child, False)
            if val > best_value:
                best_value = val
                best_path = [node] + path
        return best_value, best_path
    else:
        best_value = float('inf')
        best_path = []
        for child in tree[node]:
            val, path = min_max(child, True)
            if val < best_value:
                best_value = val
                best_path = [node] + path
        return best_value, best_path


# Main Execution
tree = input_tree()
values = assign_leaf_values(tree)
root = input("\nEnter the root node: ")

result_value, result_path = min_max(root, True)
print(f"\nBest value: {result_value}")
print(f"Best path: {' -> '.join(result_path)}")
