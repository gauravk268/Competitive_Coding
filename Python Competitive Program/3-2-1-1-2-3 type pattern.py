
# Program for pattern

N = int(input("Enter the value of N :"))
for i in range(N):
    print ((str(N - i) + "*") * (N - 1 - i) + str(N - i))
for i in range(2,N + 1):
    print((str(i) + "*") * (i - 1) + str(i))
