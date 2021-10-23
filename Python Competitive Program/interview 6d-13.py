# Python3 program to count triplets with sum that lies in given range [a, b]. 
  
# Function to count triplets 
def countTriplets(arr, n, a, b): 
      
    # Initialize result 
    ans = 0
  
    # Fix the first element as A[i] 
    for i in range(0, n - 2): 
          
        # Fix the second element as A[j] 
        for j in range(i + 1, n - 1): 
  
            # Now look for the third number 
            for k in range(j + 1, n): 
  
                if ((arr[i] + arr[j] + arr[k] >= a)  
                and (arr[i] + arr[j] + arr[k] <= b)): 
                        ans += 1
                          
    return ans 
  
# Driver code 
if __name__ == "__main__": 
      
    arr = [ 2, 7, 5, 3, 8, 4, 1, 9 ] 
    n = len(arr) 
    a = 8; b = 16
    print(countTriplets(arr, n, a, b)) 
