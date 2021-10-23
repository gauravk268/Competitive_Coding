#Intersection of two lists 
def intertwolist(A, B):
   C = [i for i in A if i in B]
   return C
# Driver Code
A=list()
B=list()
n=int(input("Enter the size of the List ::"))
print("Enter the Element of first list :: ")
for i in range(int(n)):
   k=int(input(""))
   A.append(k)
print("Enter the Element of second list :: ")
for i in range(int(n)):
   k=int(input(""))
   B.append(k)
print("THE FINAL LIST IS :: ",intertwolist(A, B))
