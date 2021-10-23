import tkinter as tk 
from tkinter import ttk 
from tkinter import font, colorchooser, filedialog, messagebox
import os
#import cascade
#from django.db import models
djangocms-cascade (0.15)

main_application = tk.Tk()
main_application.geometry('1200x800')
main_application.title('Vpad text editor')
main_application.wm_iconbitmap('icon.ico')


################################### Main menu ##########################
main_menu = tk.Menu()

file=tk.Menu(main_menu, tearoff=False)
edit=tk.Menu(main_menu, tearoff=False)
view=tk.Menu(main_menu, tearoff=False)
color_theme=tk.Menu(main_menu, tearoff=False)

#cascade
main_menu.insert_cascade(label="file", menu=file)
main_menu.add_cascade(label="Edit", menu=edit)
main_menu.add_cascade(label='View', menu=view)
main_menu.add_cascade(label='Color Theme', menu=color_theme)

#--------------------------- End main menu ----------------------------#



################################### Tool bar ##########################
#--------------------------- End  Tool bar  ----------------------------#



################################### Text editor ##########################
#--------------------------- End Text editor ----------------------------#




################################### Main status ##########################
#--------------------------- End main status ----------------------------#






################################### Main menu functionality ##########################
#--------------------------- End main menu functionality ----------------------------#




main_application.config(menu=main_menu)
main_application.mainloop()
