# Python 3 program to check whether the  sum of fibonacci elements of the  array is a Fibonacci number or not 

MAX = 100005

# Hash to store the Fibonacci numbers up to Max 
fibonacci = set() 

# Function to create the hash table to check Fibonacci numbers 
def createHash(): 

	global fibonacci 
	
	# Inserting the first two Fibonacci numbers into the hash 
	prev , curr = 0, 1
	fibonacci.add(prev) 
	fibonacci.add(curr) 

	# Add the remaining Fibonacci numbers based on the previous two numbers 
	while (curr <= MAX): 
		temp = curr + prev 
		if temp <= MAX: 
			fibonacci.add(temp) 
		prev = curr 
		curr = temp 

# Function to check if the sum of Fibonacci numbers is Fibonacci or not 
def checkArray(arr, n): 

	# Find the sum of all Fibonacci numbers 
	sum = 0
	
	# Iterating through the array 
	for i in range( n ): 
		if (arr[i] in fibonacci): 
			sum += arr[i] 

	# If the sum is Fibonacci then return true 
	if (sum in fibonacci): 
		return True

	return False

# Driver code 
if __name__ == "__main__": 
	
	# array of elements 
	arr = [ 1, 2, 4, 8, 2 ] 
	n = len(arr) 

	# Creating a set containing  all fibonacci numbers 
	createHash() 

	if (checkArray(arr, n)): 
		print("Yes") 
	else: 
		print("No") 


