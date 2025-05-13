import random
import copy

# 1) Input TSP instance
def input_tsp():
    n = int(input("Enter number of cities: "))
    print("Enter distance matrix row by row (space separated):")
    dist = []
    for i in range(n):
        row = list(map(float, input(f"Row {i+1}: ").split()))
        assert len(row) == n, "Each row must have n entries"
        dist.append(row)
    return dist

# 2) Cost of a full tour (returns to start)
def tour_cost(tour, dist):
    cost = 0
    for i in range(len(tour)):
        j = (i + 1) % len(tour)
        cost += dist[tour[i]][tour[j]]
    return cost

# 3) Generate all 2-opt neighbors
def two_opt_neighbors(tour):
    neighbors = []
    n = len(tour)
    for i in range(n - 1):
        for j in range(i + 1, n):
            nbr = tour.copy()
            nbr[i], nbr[j] = nbr[j], nbr[i]
            neighbors.append(nbr)
    return neighbors

# 4b) Stochastic Hill Climbing
def stochastic_hill_climbing(dist, start_tour, max_iters=1000):
    current = start_tour
    current_cost = tour_cost(current, dist)
    path = [current_cost]

    for _ in range(max_iters):
        better = []
        for nbr in two_opt_neighbors(current):
            c = tour_cost(nbr, dist)
            if c < current_cost:
                better.append((nbr, c))
        if not better:
            break
        nbr, c = random.choice(better)
        current, current_cost = nbr, c
        path.append(current_cost)

    return current, current_cost, path

# 5) Main
if __name__ == "__main__":
    dist = input_tsp()
    n = len(dist)
    # start with a random tour
    start = list(range(n))
    random.shuffle(start)

    print("\nInitial random tour:", start, "cost =", tour_cost(start, dist))

    tour, cost, hist = stochastic_hill_climbing(dist, start.copy())
    print("\nStochastic HC → tour:", tour, "cost =", cost)