
# Program to remove duplicate from a List

def duplicate(List):
    duplicateList = []
    for n in List:
        if n not in duplicateList:
            duplicateList.append(n)
    return duplicateList

size = int(input("Enter the no. of elements you want to add in list : "))
print("Enter the element in List one by one : ")
List = []
for i in range(size):
    List.append(input())
print("List after removing the duplicates is : ",duplicate(List))
