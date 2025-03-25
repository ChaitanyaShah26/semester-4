import random

# Define the distance matrix for the TSP
distance_matrix = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

def calculate_total_cost(path, distance_matrix):
    total_cost = 0
    num_cities = len(path)
    for i in range(num_cities):
        total_cost += distance_matrix[path[i]][path[(i + 1) % num_cities]]
    return total_cost

def get_neighbors(path):
    neighbors = []
    num_cities = len(path)
    for i in range(num_cities):
        for j in range(i + 1, num_cities):
            # Swap two cities to create a neighbor
            neighbor = path[:]
            neighbor[i], neighbor[j] = neighbor[j], neighbor[i]
            neighbors.append(neighbor)
    return neighbors

def steepest_ascent_hill_climbing(distance_matrix):
    # Initialize a random path
    num_cities = len(distance_matrix)
    current_path = list(range(num_cities))
    random.shuffle(current_path)
    
    current_cost = calculate_total_cost(current_path, distance_matrix)
    
    while True:
        neighbors = get_neighbors(current_path)
        best_neighbor = None
        best_cost = current_cost
        
        for neighbor in neighbors:
            neighbor_cost = calculate_total_cost(neighbor, distance_matrix)
            if neighbor_cost < best_cost:
                best_cost = neighbor_cost
                best_neighbor = neighbor
        
        if best_neighbor is None:
            break  # No better neighbor found, exit the loop
        
        current_path = best_neighbor
        current_cost = best_cost
    
    return current_path, current_cost

# Run the steepest ascent hill climbing algorithm
optimal_path, total_cost = steepest_ascent_hill_climbing(distance_matrix)

# Output the results
print(f"Number of cities: {len(distance_matrix)}")
print(f"Optimal path: {optimal_path}")
print(f"Total cost: {total_cost}")





# Output:
'''
Number of cities: 4
Optimal path: [1, 3, 2, 0]
Total cost: 80
'''
