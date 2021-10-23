from tkinter import*
class Login:
    def __init__(self,root):
        self.root=root
        self.root.title("FILE BASE RECORD SYSTEM")
        self.root.geometry("1350x700+0+0")

        F1=Frame(self.root,bd=10,relief=GROOVE)
        F1.place(x=450,y=150,width=450,height=300)

        title=Label(F1,text="Login System",font=("times new roman",30,"bold"))
        
    








root=Tk()
ob=Login(root)
root.mainloop()
