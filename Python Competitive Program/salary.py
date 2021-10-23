# ---- Clean the Messy salary


# 1. method
salary = '$876,001'
old = "$"
new = ""
str1=salary.replace(old,new)
old1=","
new1=""
str2=int(str1.replace(old1,new1))
print(str2)
print(type(str2))

#2. method

salary = '$876,001'
str1=salary.replace('$','')
str2=str1.split(',')
str3=int(''.join(str2))
print(str3)
print(type(str3))
