from tkinter import *
#from PIL import *
from tkinter import messagebox

class Login_system:
    def __init__(self,root):
        self.root=root
        self.root.title("Login System")
        self.root.geometry("1350x700+0+0")  #1350 ke baad small X type krna h n ki * ,first 0 start x axis,second 0 start from y axis .

        #-----------ALL Image-----------------
        #self.bg_icon=ImageTk.PhotoImage(file="icons2/bg_color.png")
        self.user_icon=PhotoImage(file="icons2/user.png")
        self.password_icon=PhotoImage(file="icons2/password.png")
        self.logo_icon=PhotoImage(file="icons2/apple.png")

        #bg_lbl=Label(self,root,image=self.bg_icon).pack()

        #title = Label(self.root, text="Login_system", font=("times new roman",40,"bold"), bg="yellow", fg="red", border=10, relief=RAISED)
        #title.place(x=0, y=0, relwidth=1)

        title=Label(self.root,text="Login System",bd=10,relief=GROOVE,font=("times new roman",40,"bold"),bg="yellow",fg="red")
        title.grid(side=TOP,fill=X)
    



root=Tk()
ob=Login_system(root)
root.mainloop()





















