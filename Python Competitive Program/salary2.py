#  ASSIGNMENT - 6
#  Clean the Messy salary from list

salary = ["$876,001" , "$543,903" , "$2453,896"]
new_salary = []
s1=''.join(salary)
print(s1)

s2=s1.replace('$','')
print(s2)
s3=s2.replace(',','')
print(s3)
s4=s3.split(" ")
print(s4)
