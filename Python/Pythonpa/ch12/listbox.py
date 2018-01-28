from tkinter import *            #导入tkinter模块所有内容
root = Tk();  root.title("Listbox")  #窗口标题
v = StringVar()
v.set(('linux','windows','unix')) 
lb = Listbox(root, selectmode=EXTENDED, listvariable = v)
lb.pack()
for item in ['python','tkinter','widget']: lb.insert(END,item) #列表框
lb.curselection()               #选择项目的索引位置：('2', '3')
for i in lb.curselection():print(lb.get(i), end=' ') #输出选择项目：unix python
root.mainloop()
