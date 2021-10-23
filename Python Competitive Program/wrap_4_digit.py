import textwrap
s = input("First line contains a string S :")
w = int(input("Second line contains the width w :").strip())
print("Print the text wrapped paragraph :")
print(textwrap.fill(s,w))
