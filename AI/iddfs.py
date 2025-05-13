def dls(tree, node, target, depth, path):
    # Add the current node to the path
    path.append(node)

    # If the target is found at the current node
    if node == target:
        return True

    # If depth limit reached, backtrack
    if depth == 0:
        path.pop()
        return False

    # Recur for all children
    for neighbor in tree.get(node, []):
        if dls(tree, neighbor, target, depth - 1, path):
            return True  # Target found in deeper call

    # If not found in this path, backtrack
    path.pop()
    return False


def iddfs(tree, start, target, max_depth):
    for depth in range(max_depth + 1):
        path = []
        if dls(tree, start, target, depth, path):
            print(f"Found {target} at depth {depth}")
            print("Path:", " -> ".join(path))
            return True
    print(f"{target} not found within depth {max_depth}")
    return False

def main():
    tree = {}
    n = int(input("Enter the number of nodes in the tree: "))

    print("Enter the tree structure:")
    for _ in range(n):
        node = input("Enter node: ").strip()
        children_input = input(f"Enter children of node '{node}' (comma separated, leave empty if none): ").strip()
        
        # Split and clean children
        if children_input:
            children = [child.strip() for child in children_input.split(',')]
        else:
            children = []
        
        tree[node] = children

    start = input("Enter the starting node: ").strip()
    target = input("Enter the target node: ").strip()
    max_depth = int(input("Enter the maximum depth for search: ").strip())
    iddfs(tree, start, target, max_depth)
if __name__ == "__main__":
    main()
    