import math

def minimax(depth, node_index, is_max, scores, height, path):
    
    if depth == height:
        return scores[node_index], path + [str(scores[node_index])]

    if is_max:
        left_value, left_path = minimax(depth + 1, node_index * 2, False, scores, height, path + ["L"])
        right_value, right_path = minimax(depth + 1, node_index * 2 + 1, False, scores, height, path + ["R"])
        if left_value > right_value:
            return left_value, left_path
        else:
            return right_value, right_path
    else:
        left_value, left_path = minimax(depth + 1, node_index * 2, True, scores, height, path + ["L"])
        right_value, right_path = minimax(depth + 1, node_index * 2 + 1, True, scores, height, path + ["R"])
        if left_value < right_value:
            return left_value, left_path
        else:
            return right_value, right_path


while True:
    try:
        scores = list(map(int, input("Enter terminal node values (space-separated)....(no. of nodes should be even) : ").split()))
        if (math.log2(len(scores))).is_integer():
            break
        else:
            print("Error: The number of values must be a power of 2 (e.g., 2, 4, 8, 16, etc.). Try again!")
    except ValueError:
        print("Invalid input! Please enter integer values.")


tree_height = int(math.log2(len(scores)))


optimal_value, optimal_path = minimax(0, 0, True, scores, tree_height, [])


print(f"\nThe optimal value is: {optimal_value}")
print(f"The optimal decision path is: {' -> '.join(optimal_path)}")
print("(L- Left path chosen, R- Right path chosen)")