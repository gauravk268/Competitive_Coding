# Simple python 3 program to find a  partition point in an array 

# Prints an element such than all elements on left are smaller and all elements on right are greater. 
def FindElement(A, n): 
	
	# traverse array elements 
	for i in range(0, n, 1): 
		
		# If we found that such number 
		flag = 0

		# check All the elements on its left are smaller
		 
		for j in range(0, i, 1): 
			if (A[j] >= A[i]): 
				flag = 1
				break

		# check All the elements on its right are Greater
		 
		for j in range(i + 1, n, 1): 
			if (A[j] <= A[i]): 
				flag = 1
				break

		# If flag == 0 indicates we found  that number
		 
		if (flag == 0): 
			return A[i] 

	return -1

# Driver Code 
if __name__ == '__main__': 
	A = [4, 3, 2, 5, 8, 6, 7] 
	n = len(A) 
	print(FindElement(A, n)) 

