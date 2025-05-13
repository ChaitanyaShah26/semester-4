def input_tree():
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

    return tree


"""def print_tree(tree, node, level=0):
    print(' ' * level + node)
    for child in tree.get(node, []):
        print_tree(tree, child, level + 2)
def main():
    tree = input_tree()
    root = input("Enter the root node: ").strip()
    
    print("\nTree structure:")
    print_tree(tree, root)
if __name__ == "__main__":
    main()"""