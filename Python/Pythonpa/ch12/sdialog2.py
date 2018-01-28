from tkinter import *            #导入tkinter模块所有内容
root = Tk()
from tkinter.simpledialog import *
dlg = SimpleDialog(root, text='继续？', buttons=['Yes','No','cancel'], default = 0)
