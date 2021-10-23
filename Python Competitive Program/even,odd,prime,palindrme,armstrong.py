# 1. odd/ even

# To take input from the user
num = int(input("Enter a number to check Odd/Even: "))
if (num % 2) == 0:
   print("{0} is Even".format(num))
else:
   print("{0} is Odd".format(num))

#---------------------------------------------------------------------------#

# 2. Program to check if a number is prime or not

# To take input from the user

num = int(input("Enter a number to check Prime number: "))

# prime numbers are greater than 1
if num > 1:
   # check for factors
   for i in range(2,num):
       if (num % i) == 0:
           print(num,"is not a prime number")
           print(i,"times",num//i,"is",num)
           break
   else:
       print(num,"is a prime number")
       
# if input number is less than
# or equal to 1, it is not prime
else:
   print(num,"is not a prime number")

#---------------------------------------------------------------------------#

# 3. Python program to check Palindrome

# To take input from the user
string=input(("Enter a string to check Palindrome:"))
if(string==string[::-1]):
      print("The string is a palindrome")
else:
      print("Not a palindrome")


#---------------------------------------------------------------------------#

   
# 4. Python program to check if the number is an Armstrong number or not

# take input from the user
num = int(input("Enter a number to check Armstrong number: "))

# initialize sum
sum = 0

# find the sum of the cube of each digit
temp = num
while temp > 0:
   digit = temp % 10
   sum += digit ** 3
   temp //= 10

# display the result
if num == sum:
   print(num,"is an Armstrong number")
else:
   print(num,"is not an Armstrong number")


#---------------------------------------------------------------------------#
































   
