## LOOPS IN PYTHON

## for loop:-

'''l1 = [10,20,30,40,50]

for item in l1:
    print(item*2)'''



# program which reads all the elements of a list and put even and odd elements in separate list.

given_list = [1,2,3,4,5,6,7,8,9,10]

# creating empty lists
 
'''even = []
odd = []

for i in given_list:
    if i%2 == 0:
        even.append(i)
    else:
        odd.append(i)

print("Even List:",even)
print("Odd List:",odd)'''


# NOTE:-
'''
range() :- returns a list of consecutive integers. It has 3 parameters where
last 2 parameters are optional.
'''
'''
for i in range(0,11,2):
    print(i*i)
'''


# Program to count no of vowels and consonants in a given name

# smart method

str1 = input("Please enter your name:")

vowel = []
conso = []

for i in str1:
    if i in "AEIOUaeiou":
        vowel.append(i)
    elif i == " ":
        pass
    else:
        conso.append(i)

print("Vowels:",vowel,"Total:",len(vowel))
print("Consonants:",conso,"Total:",len(conso))


# while loop:-

'''
1) In while loop, condition is checked first and then body of the loop
enters only if the condition evaluates to True.
2) After 1 iteration, the condition is checked again and this process
continues until the condition evaluates to false.
'''
''' 
n = 1

while n <= 10:
    print(n)
    n = n + 1
print("Bye")
'''

# break :- break keyword is used to exit a loop when an external condition is triggered.
# continue :- it is used to skip the loop for a particular condition
'''
for i in range(1,11):
    if i == 6:
        continue
    print(i,"  ",end="")
'''

# PRACTICE TIME

# Program 1
'''
Program to print the second largest no from the list and the list elements
should be entered by the user
'''
'''
num = int(input("How many no of elements do you want to enter:"))
list1 = []


for i in range(num):
    list1.append(int(input("Enter the element:")))

print("Original List:",list1)

list1.sort()  # to sort the element in ascending order

print("Sorted List:",list1)

print("Second Largest:",list1[-2])
'''
