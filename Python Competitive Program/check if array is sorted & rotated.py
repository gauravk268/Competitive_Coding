# Python3 program to check if an array is sorted and rotated clockwise 
import sys 

# Function to check if an array is sorted and rotated clockwise 
def checkIfSortRotated(arr, n): 
	minEle = sys.maxsize 
	maxEle = -sys.maxsize - 1
	minIndex = -1

	# Find the minimum element and it's index 
	for i in range(n): 
		if arr[i]< minEle: 
			minEle = arr[i] 
			minIndex = i 
	flag1 = 1

	# Check if all elements before minIndex are in increasing order 
	for i in range(1, minIndex): 
		if arr[i] < arr[i - 1]: 
			flag1 = 0
			break
	flag2 = 2

	# Check if all elements after minIndex are in increasing order 
	for i in range(minIndex + 1, n) : 
		if arr[i] < arr[i - 1]: 
			flag2 = 0
			break

	# Check if last element of the array is smaller than the element just before the element at minIndex 
	if (flag1 and flag2 and
		arr[n - 1] < arr[minIndex - 1]): 
		print("YES") 
	else: 
		print("NO") 

# Driver code 
arr = [3, 4, 5, 1, 2 ] 
n = len(arr) 
checkIfSortRotated(arr, n) 

