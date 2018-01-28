from tkinter import *                #导入tkinter模块所有内容
root = Tk();  root.title("Radiobutton")  #窗口标题
v = StringVar();v.set('M')    #创建StringVar对象，并设置初始值
w1 = Radiobutton(root, text="男", value='M', variable=v)
w2 = Radiobutton(root, text="女", value='F', variable=v)
w1.pack(side=LEFT) 
w2.pack(side=LEFT) 
v.get()             #选择女后，获取其值：'F'
root.mainloop()
