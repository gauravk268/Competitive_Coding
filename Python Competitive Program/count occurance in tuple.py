
# Count occurrences of an element 

str=input("Enter the string : ")
word_count={char:str.count(char) for char in str}
print(word_count)
