from tkinter import *
from random import randint

root = Tk()

root.title("RAVI GUESS THE NUMBER")

root.geometry("600x200")

class ValueSmallError(Exception):
    pass

class ValueLargeError(Exception):
    pass

ans = randint(1,100)

def guess():
    num = int(num1.get())

    try:
        if num > ans:
            raise ValueLargeError
        elif num < ans:
            raise ValueSmallError
        else:
            Label(root,text = "Congratulations RAVI, You won ,give the PARTY!!").grid(column=0,row=3)
    except ValueLargeError:
        Label(root, text =  "Your no is large, guess again").grid(column=0, row=3)
    except ValueSmallError:
        Label(root,text = "Your no is small, guess again").grid(column=0, row=3)
    return


Label(root,text="\t\t\t*** RAVI GUESS THE NUMBER ***").grid(column=0,row=0)

Label(root,text="\nGuess the number(1-100)").grid(column=0,row=1)

num1 = Entry(root)
num1.grid(column=1,row=1)

btn1 = Button(root,text="Submit",command=guess).grid(column=1,row=3)

root.mainloop()
         

 
