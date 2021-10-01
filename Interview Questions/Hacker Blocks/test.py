n = int(input())

employees = []

for i in range(n):
    (name, inTime, outTime) = input().split(',')
    employees.append([name, inTime, outTime])

q = int(input())

for i in range(q):
    queryTime = input()
    cnt = 0
    for employee in employees:
        inTime = str(employee[1])
        outTime = str(employee[2])

        if(inTime <= queryTime)
            cnt += 1
print(cnt)