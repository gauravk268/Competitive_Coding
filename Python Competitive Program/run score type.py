Batsman1 = int(input("Enter the runs scored by first batsman in 60 balls: "))
Batsman2 = int(input("Enter the runs scored by second batsman in 60 balls: "))
Batsman3 = int(input("Enter the runs scored by third batsman in 60 balls: "))

Strikerate1 = Batsman1 * 100 / 60
Strikerate2 = Batsman2 * 100 / 60
Strikerate3 = Batsman3 * 100 / 60

print("strike rate of first batsman is ", Strikerate1)
print("strike rate of second batsman is ", Strikerate2)
print("strike rate of third  batsman is ", Strikerate3)

print("Runs scored by first batsman if they played 60 more balls is ", Batsman1 * 2)
print("Runs scored by second batsman if they played 60 more balls is ", Batsman2 * 2)
print("Runs scored by third batsman if they played 60 more balls is ", Batsman3 * 2)

print("Maximum number of sixes of first batsman could hit =", Batsman1 // 6)
print("Maximum number of sixes of second batsman could hit =", Batsman2 // 6)
print("Maximum number of sixes of third batsman could hit =", Batsman3 // 6)
