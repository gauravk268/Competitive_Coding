for i in range(2, 101, 2):
    for j in range(2, 101, 2):
        sum = i+j
        print(sum,end='  ')
        if(sum>100):
            break