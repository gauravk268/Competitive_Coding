import textwrap

#First line contains a string S

S = input("Enter your string : ")

#Second line contains the width w

w = int(input("Please write which width you want in string : "))
print (textwrap.fill(S,w))
