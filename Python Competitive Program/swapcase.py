def SwapCase(str):
    length=len(str)

    for i in range(length):
        if str[i]>='a' and str[i]<='z':
            str[i]=chr(ord(str[i])-32)
        elif str[i]>='A' and str[i]<='Z':
            str[i]=chr(ord(str[i])+32)


if __name__ == "__main__":
    
    str=input("A single line containing a string S : ")
    str=list(str)

    SwapCase(str)
    str="".join(str)
    print("Print the modified string S :"+ str)

    
