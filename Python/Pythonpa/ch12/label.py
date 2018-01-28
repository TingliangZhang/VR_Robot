from tkinter import *                 #导入tkinter模块所有内容
root = Tk();root.title("Label示例")      #窗口标题
w = Label(root, text="姓名")           #创建Label组件对象，显示文本为"姓名"
w.config(width=20, bg='black', fg='white') #设置宽度、背景色、前景色
w['anchor'] = E                      #设置停靠方式为右对齐
w.pack()
root.mainloop()
