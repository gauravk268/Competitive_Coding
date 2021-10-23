# Assignment - 2
# Ride Cost Calculator
import math
a = int(input("Total travelling distance km is : "))
b = int(input("Cost of Diesel per litre in INR is : "))
c = int(input("Vehicle Fuel Average in km/litre is : "))

d = a/c
e = b/d

print("Fuel Consumption is : ",d)
print("Cost per day is : ",e)
