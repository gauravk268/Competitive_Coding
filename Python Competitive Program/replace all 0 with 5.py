
#  Program for replace all 0 with 5 in an input integer

def replace0with5(number): 
    number += calculateAddedValue(number) 
    return number 
      
# returns the number to be added to the input to replace all zeroes with five 

def calculateAddedValue(number): 
      
    # amount to be added 
    result = 0
      
    # unit decimal place 
    decimalPlace = 1
  
    if (number == 0): 
        result += (5 * decimalPlace) 
          
    while (number > 0): 
        if (number % 10 == 0): 
              
            # a number divisible by 10, then 
            # this is a zero occurrence in the input 
            result += (5 * decimalPlace) 
              
        # move one decimal place 
        number //= 10
        decimalPlace *= 10
      
    return result 
      
# Driver code 
print(replace0with5(int(input("Enter the number for replace : "))))
