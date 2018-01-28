from tkinter import *            #导入tkinter模块所有内容
root = Tk();  root.title("选择项")  #窗口标题
v = StringVar(root)
v.set('Python')
om = OptionMenu(root,v,'Python','Perl','JavaScript','C#')
om['width']=10
om['anchor']=W
om.pack()
root.mainloop()
