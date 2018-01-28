from tkinter import *            #导入tkinter模块所有内容
root = Tk();  root.title("Text")    #窗口标题
w = Text(root, width=20, height=5) #创建文本框，宽20，高5
w.pack()
w.insert(1.0, '生，还是死，这是一个问题！\n ')
w.get(1.0)  #'生'
w.get(1.0, END)  #'生，还是死，这是一个问题！\n'
root.mainloop()
