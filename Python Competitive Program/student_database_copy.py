from tkinter import *
from tkinter import ttk
import pymysql

class Student:
    def __init__(self,root):
        self.root=root
        self.root.title("Student Management System")  ##1350 ke baad small X type krna h n ki * ,first 0 start x axis,second 0 start from y axis .
        self.root.geometry("1350x700+0+0")


        title=Label(self.root,text="Student Management System",bd=10,relief=GROOVE,font=("times new roman",40,"bold"),bg="khaki",fg="dimgray")
        title.pack(side=TOP,fill=X)

        self.Roll_No_Var=StringVar()
        self.name_Var=StringVar()
        self.email_Var=StringVar()
        self.gender_Var=StringVar()
        self.contact_Var=StringVar()
        self.dob_Var=StringVar()
        self.Address_Var=StringVar()

        self.search_by=StringVar()
        self.search_txt=StringVar()


        

        #======================== Manage_Frame =========================

        Manage_Frame=Frame(self.root,bd=4,relief=RIDGE,bg="crimson")
        Manage_Frame.place(x=20,y=100,width=450,height=580)

        m_title=Label(Manage_Frame,text="Manage_Frame",bg="crimson",fg="white",font=("times new roman",20,"bold"))
        m_title.grid(row=0,columnspan=2,pady=20)

        lbl_roll=Label(Manage_Frame,text="Roll No",bg="crimson",fg="white",font=("times new roman",20,"bold"))
        lbl_roll.grid(row=1,column=0,pady=10,padx=20,sticky="w")

        txt_Roll=Entry(Manage_Frame,textvariable=self.Roll_No_Var,font=("times new roman",15,"bold"),bd=5,relief=GROOVE)
        txt_Roll.grid(row=1,column=1,pady=10,padx=20,sticky="w")

        lbl_Name=Label(Manage_Frame,text="Name",bg="crimson",fg="white",font=("times new roman",20,"bold"))
        lbl_Name.grid(row=2,column=0,pady=10,padx=20,sticky="w")

        txt_Name=Entry(Manage_Frame,textvariable=self.name_Var,font=("times new roman",15,"bold"),bd=5,relief=GROOVE)
        txt_Name.grid(row=2,column=1,pady=10,padx=20,sticky="w")

        lbl_Email=Label(Manage_Frame,text="Email",bg="crimson",fg="white",font=("times new roman",20,"bold"))
        lbl_Email.grid(row=3,column=0,pady=10,padx=20,sticky="w")

        txt_Email=Entry(Manage_Frame,textvariable=self.email_Var,font=("times new roman",15,"bold"),bd=5,relief=GROOVE)
        txt_Email.grid(row=3,column=1,pady=10,padx=20,sticky="w")

        lbl_Gender=Label(Manage_Frame,text="Gender",bg="crimson",fg="white",font=("times new roman",20,"bold"))
        lbl_Gender.grid(row=4,column=0,pady=10,padx=20,sticky="w")

        combo_gender=ttk.Combobox(Manage_Frame,textvariable=self.gender_Var,font=("times new roman",13,"bold"),state='readonly')
        combo_gender["values"]=("Male","Female","Other")
        combo_gender.grid(row=4,column=1,pady=10,padx=20)


        

        lbl_Contact=Label(Manage_Frame,text="Contact",bg="crimson",fg="white",font=("times new roman",20,"bold"))
        lbl_Contact.grid(row=5,column=0,pady=10,padx=20,sticky="w")

        txt_Contact=Entry(Manage_Frame,textvariable=self.contact_Var,font=("times new roman",15,"bold"),bd=5,relief=GROOVE)
        txt_Contact.grid(row=5,column=1,pady=10,padx=20,sticky="w")

        lbl_D_O_B=Label(Manage_Frame,text="D.O.B",bg="crimson",fg="white",font=("times new roman",20,"bold"))
        lbl_D_O_B.grid(row=6,column=0,pady=10,padx=20,sticky="w")

        txt_D_O_B=Entry(Manage_Frame,textvariable=self.dob_Var,font=("times new roman",15,"bold"),bd=5,relief=GROOVE)
        txt_D_O_B.grid(row=6,column=1,pady=10,padx=20,sticky="w")

        lbl_Address=Label(Manage_Frame,text="Address",bg="crimson",fg="white",font=("times new roman",20,"bold"))
        lbl_Address.grid(row=7,column=0,pady=10,padx=20,sticky="w")

        txt_Address=Entry(Manage_Frame,textvariable=self.Address_Var,font=("times new roman",15,"bold"),bd=5,relief=GROOVE)
        txt_Address.grid(row=7,column=1,pady=25,padx=25,sticky="w")

        #============================ Button frame ==========================================

        btn_Frame=Frame(self.root,bd=4,relief=RIDGE,bg="crimson")
        btn_Frame.place(x=20,y=620,width=445)

        Addbtn=Button(btn_Frame,text="Add",width=10,command=self.add_students).grid(row=0,column=0,padx=10,pady=10)
        updatebtn=Button(btn_Frame,text="Update",width=10,command=self.update_data).grid(row=0,column=1,padx=10,pady=10)
        deletebtn=Button(btn_Frame,text="Delete",width=10,command=self.delete_data).grid(row=0,column=2,padx=10,pady=10)
        clearbtn=Button(btn_Frame,text="Clear",width=10,command=self.clear).grid(row=0,column=3,padx=10,pady=10)
        

        

        

        








        #======================== Detail_Frame =========================

        Detail_Frame=Frame(self.root,bd=4,relief=RIDGE,bg="crimson")
        Detail_Frame.place(x=500,y=100,width=800,height=580)


        lbl_search=Label(Detail_Frame,text="Search by",bg="crimson",fg="white",font=("times new roman",20,"bold"))
        lbl_search.grid(row=0,column=0,pady=10,padx=20,sticky="w")

        combo_search=ttk.Combobox(Detail_Frame,textvariable=self.search_by,width=10,font=("times new roman",13,"bold"),state='readonly')
        combo_search["values"]=("Roll_No","Name","Contact")
        combo_search.grid(row=0,column=1,pady=10,padx=20)

        txt_search=Entry(Detail_Frame,textvariable=self.search_txt,width=20,font=("times new roman",10,"bold"),bd=5,relief=GROOVE)
        txt_search.grid(row=0,column=2,pady=10,padx=20,sticky="w")

        searchbtn=Button(Detail_Frame,text="Search",width=10,pady=5,textvariable=self.search_data).grid(row=0,column=3,padx=10,pady=10)
        showallbtn=Button(Detail_Frame,text="Show All",width=10,pady=5,textvariable=self.fetch_data).grid(row=0,column=4,padx=10,pady=10)

        #===================================  Table Frame  =====================================================

        Table_Frame=Frame(Detail_Frame,bd=4,relief=RIDGE,bg="crimson")
        Table_Frame.place(x=10,y=70,width=770,height=500)

        scroll_x=Scrollbar(Table_Frame,orient=HORIZONTAL)
        scroll_y=Scrollbar(Table_Frame,orient=VERTICAL)
        self.Student_table=ttk.Treeview(Table_Frame,columns=("roll","name","email","gender","contact","dob","Address"),xscrollcommand=scroll_x.set,yscrollcommand=scroll_y.set)
        scroll_x.pack(side=BOTTOM,fill=X)
        scroll_y.pack(side=RIGHT,fill=Y)
        scroll_x.config(command=self.Student_table.xview)
        scroll_y.config(command=self.Student_table.yview)
        self.Student_table.heading("roll",text="Roll No")
        self.Student_table.heading("name",text="Name")
        self.Student_table.heading("email",text="Email")
        self.Student_table.heading("gender",text="Gender")
        self.Student_table.heading("contact",text="Contact")
        self.Student_table.heading("dob",text="D.O.B")
        self.Student_table.heading("Address",text="Address")
        self.Student_table['show']='headings'

        self.Student_table.column("roll",width=100)
        self.Student_table.column("name",width=100)
        self.Student_table.column("email",width=100)
        self.Student_table.column("gender",width=100)
        self.Student_table.column("contact",width=100)
        self.Student_table.column("dob",width=100)
        self.Student_table.column("Address",width=140)

        self.Student_table.pack(fill=BOTH,expand=1)
        self.Student_table.bind("<ButtonRelease-1>",self.get_cursor)
        self.fetch_data()
    def add_students(self):
        con=pymysql.connect(host="localhost",user="root",password="Mishra@21",database="ravi")          # create database name on phpmyadmin = smd
        cur=con.cursor()
        cur.execute("insert into kumar values(%s,%s,%s,%s,%s,%s,%s)",(self.Roll_No_Var.get(),
                                                                         self.name_Var.get(),
                                                                         self.email_Var.get(),
                                                                         self.gender_Var.get(),
                                                                         self.contact_Var.get(),
                                                                         self.dob_Var.get(),
                                                                         self.Address_Var.get()
                                                                         ))
        con.commit()
        self.fetch_data()
        self.clear()
        con.close()
    def fetch_data(self):
        con=pymysql.connect(host="localhost",user="root",password="Mishra@21",database="ravi")          # create database name on phpmyadmin = smd
        cur=con.cursor()
        cur.execute("select * from kumar")
        rows=cur.fetchall()
        if len(rows)!=0:
            self.Student_table.delete(*self.Student_table.get_children())
            for row in rows:
                self.Student_table.insert('',END,values=row)
                con.commit()
        con.close()

    def clear(self):
        self.Roll_No_Var.set(""),
        self.name_Var.set(""),
        self.email_Var.set(""),
        self.gender_Var.set(""),
        self.contact_Var.set(""),
        self.dob_Var.set(""),
        self.Address_Var.set("")


    def get_cursor(self,ev):
        cursor_row=self.Student_table.focus()
        contents=self.Student_table.item(cursor_row)
        row=contents['values']

        self.Roll_No_Var.set(row[0]),
        self.name_Var.set(row[1]),
        self.email_Var.set(row[2]),
        self.gender_Var.set(row[3]),
        self.contact_Var.set(row[4]),
        self.dob_Var.set(row[5]),
        self.Address_Var.set(row[6])

    def update_data(self):
        con=pymysql.connect(host="localhost",user="root",password="Mishra@21",database="ravi")          # create database name on phpmyadmin = smd
        cur=con.cursor()
        cur.execute("update kumar set name=%s,email=%s,gender=%s,contact=%s,d_o_b=%s,address=%s where roll_no=%s",(
                                                                         self.name_Var.get(),
                                                                         self.email_Var.get(),
                                                                         self.gender_Var.get(),
                                                                         self.contact_Var.get(),
                                                                         self.dob_Var.get(),
                                                                         self.Address_Var.get(),
                                                                         self.Roll_No_Var.get()
                                                                         ))
        con.commit()
        self.fetch_data()
        self.clear()
        con.close()

    def delete_data(self):
        con=pymysql.connect(host="localhost",user="root",password="Mishra@21",database="ravi")          # create database name on phpmyadmin = smd
        cur=con.cursor()
        cur.execute("delete from kumar where roll_no=%s",self.Roll_No_Var.get())
        con.commit()
        con.close()
        self.fetch_data()
        self.clear()

    def search_data(self):
        con=pymysql.connect(host="localhost",user="root",password="Mishra@21",database="ravi")          # create database name on phpmyadmin = smd
        cur=con.cursor()
        
        cur.execute("select * from kumar where "+str(self.search_by.get())+" LIKE '%"+str(self.search_txt.get())+"%'")
        rows=cur.fetchall()
        if len(rows)!=0:
                self.Student_table.delete(*self.Student_table.get_children())
                for row in rows:
                        self.Student_table.insert('',END,values=row)
                        con.commit()
                        con.close()
        

        
                                                        
            
        

                                                                         

        









































root=Tk()
ob=Student(root)
root.mainloop()
