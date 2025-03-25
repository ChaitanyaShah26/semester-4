import random

def generate_population(size, length):
    return [''.join(random.choice('01') for _ in range(length)) for _ in range(size)]

def calculate_fitness(population):
    return [individual.count('1') for individual in population]

def select_parents(population, fitness):
    # Select the two parents with the highest fitness
    parents_indices = sorted(range(len(fitness)), key=lambda i: fitness[i], reverse=True)[:2]
    return population[parents_indices[0]], population[parents_indices[1]], fitness[parents_indices[0]], fitness[parents_indices[1]]

def crossover(parent1, parent2, crossover_length):
    crossover_point = random.randint(0, len(parent1) - crossover_length)
    offspring1 = parent1[:crossover_point] + parent2[crossover_point:crossover_point + crossover_length] + parent1[crossover_point + crossover_length:]
    offspring2 = parent2[:crossover_point] + parent1[crossover_point:crossover_point + crossover_length] + parent2[crossover_point + crossover_length:]
    return offspring1, offspring2

def mutate(offspring, num_mutations):
    offspring_list = list(offspring)
    for _ in range(num_mutations):
        mutation_index = random.randint(0, len(offspring_list) - 1)
        offspring_list[mutation_index] = '1' if offspring_list[mutation_index] == '0' else '0'
    return ''.join(offspring_list)

def main():
    # User inputs
    population_size = int(input("Enter population size: "))
    population = generate_population(population_size, 8)
    print("Generated Population:")
    for individual in population:
        print(individual)

    offspring_count = int(input("Enter number of offspring to generate : "))
    crossover_length = int(input("Enter length to crossover: "))
    num_mutations = int(input("Enter number of mutations to perform: "))

    # Calculate fitness
    fitness = calculate_fitness(population)
    print("Fitness:")
    for individual, fit in zip(population, fitness):
        print(f"Individual: {individual}, Fitness: {fit}")

    # Select parents
    parent1, parent2, fitness1, fitness2 = select_parents(population, fitness)
    print("Selected Parents:")
    print(f"Parent 1: {parent1}, Fitness: {fitness1}")
    print(f"Parent 2: {parent2}, Fitness: {fitness2}")

    # Generate offspring
    offspring_list = []
    for _ in range(offspring_count):
        offspring1, _ = crossover(parent1, parent2, crossover_length)
        offspring_list.append(offspring1)

    print("Offsprings before mutation:")
    for offspring in offspring_list:
        print(offspring)

    # Mutate offspring
    mutated_offsprings = [mutate(offspring, num_mutations) for offspring in offspring_list]
    print("Final Mutated Offsprings:")
    for mutated_offspring in mutated_offsprings:
        print(mutated_offspring)

if __name__ == "__main__":
    main()








# Output
'''
Enter population size: 4
Generated Population:
11110010
11101010
00001001
00100010
Enter number of offspring to generate : 2
Enter length to crossover: 3
Enter number of mutations to perform: 2
Fitness:
Individual: 11110010, Fitness: 5
Individual: 11101010, Fitness: 5
Individual: 00001001, Fitness: 2
Individual: 00100010, Fitness: 2
Parent 1: 11110010, Fitness: 5
Parent 2: 11101010, Fitness: 5
Offsprings before mutation:
11110010
11100010
Final Mutated Offsprings:
11111110
11111010
'''