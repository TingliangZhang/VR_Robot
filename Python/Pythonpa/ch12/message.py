from tkinter import *              #导入tkinter模块所有内容
root = Tk();  root.title("Message")   #窗口标题
w = Message(root, bg='black', fg='white')          #创建Message组件对象
w.config(text="内容显示在一个宽高比为150%的消息框中") #设置显示文本
w['anchor'] = W                               #设置停靠方式为左对齐
w.pack()
root.mainloop()
