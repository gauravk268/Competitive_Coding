def fact(n):
    if n==0:
        return 1
    else:
        return n*fact(n-1)

n = int(input(""))
result = fact(n)
print("factorial of",n,"is",result)
