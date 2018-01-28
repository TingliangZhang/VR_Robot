from tkinter import *      #导入tkinter模块
root = Tk()
from tkinter.simpledialog import *
i = askinteger(title='请输入', prompt='请输入整数:',initialvalue=100)
f = askfloat(title='请输入', prompt='请输入实数:')
s = askstring(title='请输入', prompt='请输入字符串:')
