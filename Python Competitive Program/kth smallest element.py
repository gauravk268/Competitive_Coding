
#  python program for given a list and a number K, where K is smaller than size of list, the task is to find the Kth smallest element in the given list. it is given that all list element are distinct .


# Python3 program to find k'th smallest element 

# Function to return k'th smallest element in a given array 
def kthSmallest(arr, n, k): 

	# Sort the given array 
	arr.sort() 

	# Return k'th element in the sorted array 
	return arr[k-1] 

# Driver code 
if __name__=='__main__': 
	arr = [12, 3, 5, 7, 19] 
	n = len(arr) 
	k = 2
	print("K'th smallest element is", 
		kthSmallest(arr, n, k)) 

