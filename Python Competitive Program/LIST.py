Python 3.8.2 (tags/v3.8.2:7b3ab59, Feb 25 2020, 22:45:29) [MSC v.1916 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> ## LISTS IN PYTHON
>>> 
>>> list1 = [10,20,30,"hello",2.4]
>>> list1
[10, 20, 30, 'hello', 2.4]
>>> list1[1]
20
>>> list1[-4]
20
>>> ## Accessing the list elements
>>> 
>>> list1 = [10,20,30,40,50,60,70,80]
>>> 
>>> list1[0]
10
>>> # suppose i want to acess range of characters
>>> 
>>> # so here is the format:  list_var_name[start:end:skip_char]
>>> 
>>> list1[1:7:1]
[20, 30, 40, 50, 60, 70]
>>> list1[7:-8:2]
[]
>>> ## Let's KBP
>>> 
>>> 
>>> 
>>> 
>>> l = [0,1,2,3,4,5,6,7,8,9,10]
>>> 
>>> 
>>> 
>>> 
>>> 
>>> 
>>> 
>>> 
>>> l[::-2]
[10, 8, 6, 4, 2, 0]
>>> 
>>> 
>>> 
>>> ## Can you tell me
>>> ## how to print a list in reverse order in single line
>>> 
>>> l
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
>>> l[::-1]
[10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
>>> 
>>> 
>>> ## Changing the elements of a list
>>> 
>>> l = [10,20,30]
>>> l[2]
30
>>> ## i want to store the new element say 300 at 2nd index no
>>> l[2] = 300
>>> l
[10, 20, 300]
>>> l[2]
300
>>> 
>>> 
>>> str_var = "Agnesh"
>>> str_var[0]
'A'
>>> str_var[0] = "B"
Traceback (most recent call last):
  File "<pyshell#54>", line 1, in <module>
    str_var[0] = "B"
TypeError: 'str' object does not support item assignment
>>> 
>>> 
>>> # suppose i want to insert rane of characters
>>> 
>>> 
>>> l = [10,20,300]
>>> ## let's change multiple values at a time
>>> l[0:2]
[10, 20]
>>> l[0:2] = [11,22]
>>> l
[11, 22, 300]
>>> l[0:2] = [1,2,3,4,5]
>>> l
[1, 2, 3, 4, 5, 300]
>>> 
>>> 
>>> 
>>> 
>>> # List Built-In Functions
>>> 
>>> ## append() :- it adds one element at the end of list
>>> 
>>> l = [10,20,30]
>>> l.append(40)
>>> l
[10, 20, 30, 40]
>>> 
>>> 
>>> ## insert() :- adds element to the list based on index no
>>> 
>>> l = [10,20,30]
>>> l.insert(2,1000)
>>> l
[10, 20, 1000, 30]
>>> 
>>> 
>>> 
