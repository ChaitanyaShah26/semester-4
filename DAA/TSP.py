import sys

n = int(input("Enter number of cities: "))
dist = []

print("Enter distance matrix:")
for _ in range(n):
    dist.append(list(map(int, input().split())))

visited = [0] * n
dp = [[-1] * (n + 1) for _ in range(n)]
path = [0] * (n + 1)
best_path = [0] * (n + 1)
min_cost = float('inf')

def tsp(pos, count):
    global min_cost, best_path

    if count == n:
        return dist[pos][0]

    if dp[pos][count] != -1:
        return dp[pos][count]

    ans = float('inf')

    for city in range(n):
        if visited[city] == 0:
            visited[city] = 1
            path[count] = city
            cost = dist[pos][city] + tsp(city, count + 1)

            if count == 1 and cost < min_cost:
                min_cost = cost
                best_path[:n] = path[:n]
                best_path[n] = 0

            ans = min(ans, cost)
            visited[city] = 0  # backtrack

    dp[pos][count] = ans
    return ans

visited[0] = 1
path[0] = 0
result = tsp(0, 1)

print("\nMinimum cost:", result)
print("Optimal Path:", ' -> '.join(str(city) for city in best_path[:n+1]))
