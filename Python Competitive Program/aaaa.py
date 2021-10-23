import numpy
import ga

"""
The y=target is to maximize this equation ASAP:
    y = w1x1+w2x2+w3x3+w4x4
    where (x1,x2,x3,x4)=(1,2,3,4)
    What are the best values for the 6 weights w1 to w6?
    We are going to use the genetic algorithm for the best possible values after a number of generations.
"""

# Inputs of the equation.
equation_inputs = [1,2,3,4]

# Number of the weights we are looking to optimize.
num_weights = len(equation_inputs)

"""
Genetic algorithm parameters:
    Mating pool size
    Chromosome size
"""
sol_per_pop = 8
num_parents_mating = 4

# Defining the Chromosome size.
pop_size = (sol_per_pop,num_weights) # The Chromosome will have sol_per_pop chromosome where each chromosome has num_weights genes.
#Creating the initial Chromosome.
new_Chromosome = numpy.random.uniform(low=-4.0, high=4.0, size=pop_size)
print(new_Chromosome)

"""
new_Chromosome[0, :] = [12,  05,  23,  08]
new_Chromosome[1, :] = [02,  21,  18,  03]
new_Chromosome[2, :] = [10,  04,  13,  14]
new_Chromosome[3, :] = [20,  01,  10,  06]
new_Chromosome[4, :] = [01,  04,  13,  19]
new_Chromosome[5, :] = [20,  05,  17,  01]
"""

best_outputs = []
num_generations = 1000
for generation in range(num_generations):
    print("Generation : ", generation)
    # Measuring the fitness of each chromosome in the Chromosome.
    fitness = ga.cal_pop_fitness(equation_inputs, new_Chromosome)
    print("Fitness")
    print(fitness)

    best_outputs.append(numpy.max(numpy.sum(new_Chromosome*equation_inputs, axis=1)))
    # The best result in the current iteration.
    print("Best result : ", numpy.max(numpy.sum(new_Chromosome*equation_inputs, axis=1)))
    
    # Selecting the best parents in theChromosomen for mating.
    parents = ga.select_mating_pool(new_Chromosome, fitness, 
                                      num_parents_mating)
    print("Parents")
    print(parents)

    # Generating next generation using crossover.
    offspring_crossover = ga.crossover(parents,
                                       offspring_size=(pop_size[0]-parents.shape[0], num_weights))
    print("Crossover")
    print(offspring_crossover)

    # Adding some variations to the offspring using mutation.
    offspring_mutation = ga.mutation(offspring_crossover, num_mutations=2)
    print("Mutation")
    print(offspring_mutation)

    # Creating the new Chromosome based on the parents and offspring.
    new_Chromosome[0:parents.shape[0], :] = parents
    new_Chromosome[parents.shape[0]:, :] = offspring_mutation
    
# Getting the best solution after iterating finishing all generations.
#At first, the fitness is calculated for each solution in the final generation.
fitness = ga.cal_pop_fitness(equation_inputs, new_Chromosome)
# Then return the index of that solution corresponding to the best fitness.
best_match_idx = numpy.where(fitness == numpy.max(fitness))

print("Best solution : ", new_Chromosome[best_match_idx, :])
print("Best solution fitness : ", fitness[best_match_idx])


import matplotlib.pyplot
matplotlib.pyplot.plot(best_outputs)
matplotlib.pyplot.xlabel("Iteration")
matplotlib.pyplot.ylabel("Fitness")
matplotlib.pyplot.show()