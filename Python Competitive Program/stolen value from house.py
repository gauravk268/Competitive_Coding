# Python3 program to find the maximum stolen value 
  
# calculate the maximum stolen value 
def maximize_loot(hval, n): 
    if n == 0: 
        return 0
    if n == 1: 
        return hval[0] 
    if n == 2: 
        return max(hval[0], hval[1]) 
  
    # dp[i] represent the maximum value stolen so 
    # for after reaching house i. 
    dp = [0]*n 
  
    # Initialize the dp[0] and dp[1] 
    dp[0] = hval[0] 
    dp[1] = max(hval[0], hval[1]) 
      
    # Fill remaining positions 
    for i in range(2, n): 
        dp[i] = max(hval[i]+dp[i-2], dp[i-1]) 
  
    return dp[-1] 
  
# Driver to test above code  
def main(): 
  
    # Value of houses 
    hval = [6, 7, 1, 3, 8, 2, 4] 
  
    # number of houses 
    n = len(hval) 
    print("Maximum loot value : {}". 
        format(maximize_loot(hval, n))) 
  
if __name__ == '__main__': 
    main() 
