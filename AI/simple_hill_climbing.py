def input_tree():
    tree = {}
    n = int(input("Enter the number of nodes in the tree: "))
    print("Enter each node and its children (comma-separated), leave blank if none.")
    for _ in range(n):
        node = input("Node: ")
        children = input(f"Children of {node}: ").split(',')
        tree[node] = [child.strip() for child in children if child.strip()]
    return tree

def assign_values(tree):
    values = {}
    all_nodes = set(tree.keys())  # parent nodes
    for children in tree.values():
        all_nodes.update(children)  # add child nodes

    for node in all_nodes:
        val = int(input(f"Enter value for node '{node}': "))
        values[node] = val
    return values

def simple_hill_climbing(tree, values, start):
    current = start
    path = [current]

    while tree.get(current):
        next_node = max(tree[current], key=lambda x: values[x])
        if values[next_node] > values[current]:
            current = next_node
            path.append(current)
        else:
            break

    print("\nSimple Hill Climbing Path:", " -> ".join(path))
    print("Reached Node:", current, "| Value:", values[current])

if __name__ == "__main__":
    tree = input_tree()
    values = assign_values(tree)
    start = input("Enter start node: ")

    simple_hill_climbing(tree, values, start)