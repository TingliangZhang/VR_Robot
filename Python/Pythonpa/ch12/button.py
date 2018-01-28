from tkinter import *            #导入tkinter模块所有内容
root = Tk();  root.title("Button")  #窗口标题
w = Button(root, text="确定") #创建Button组件对象，显示文本为"确定"
w.config(state=DISABLED)  #设置Label组件的状态为禁用
w['width'] = 20             #设置宽度
w.pack()
root.mainloop()
