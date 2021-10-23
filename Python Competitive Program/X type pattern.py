
# Program for star pattern

n = int(input("Enter the value of N :"))
for i in range(n):
    print (" " * i + "*" + "  " * (n - 1 - i) + "*")
for i in range(n):
    print(" " * (n - 1 - i) + "*" + "  " * i + "*")
