def duplicate(string):
    duplicatestring = ""
    for i in string:
        if i not in duplicatestring:
            duplicatestring += i
    return duplicatestring
string = input("Enter the string : ")
print("After removing the duplicates , the string is : ", duplicate(string))
