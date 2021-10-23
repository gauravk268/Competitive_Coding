# Python program to sort array  in even and odd manner  The odd numbers are to be  sorted in descending order  and the even numbers in  ascending order 

# To do two way sort. First  sort even numbers in ascending  order, then odd numbers in  descending order. 

def two_way_sort(arr, arr_len): 
	
	# Current indexes l->left  and r->right 
	l, r = 0, arr_len - 1
	
	# Count of number of  odd numbers, used in  slicing the array later. 
	k = 0
	
	# Run till left(l) < right(r) 
	while(l < r): 
		
		# While left(l) is odd, if yes 
		# increment the left(l) plus 
		# odd count(k) if not break the 
		# while for even number found 
		# here to be swaped 
		while(arr[l] % 2 != 0): 
			l += 1
			k += 1
			
		# While right(r) is even, 
		# if yes decrement right(r) 
		# if not break the while for 
		# odd number found here to 
		# be swaped	 
		while(arr[r] % 2 == 0 and l < r): 
			r -= 1
			
		# Swap the left(l) and right(r), 
		# which is even and odd numbers 
		# encountered in above loops 
		if(l < r): 
			arr[l], arr[r] = arr[r], arr[l] 
			
	# Slice the number on the 
	# basis of odd count(k) 
	odd = arr[:k] 
	even = arr[k:] 
	
	# Sort the odd and 
	# even array accordingly 
	odd.sort(reverse = True) 
	even.sort() 
	
	# Extend the odd array with 
	# even values and return it. 
	odd.extend(even) 
	
	return odd 
	
# Driver code 
arr_len = 10
arr = [1, 3, 2, 7, 5, 4, 6, 8, 12, 13] 
result = two_way_sort(arr, arr_len) 
for i in result: 
	print(str(i) + " "), 

