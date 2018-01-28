from tkinter import *           #导入tkinter模块所有内容
root = Tk(); root.title("LabelFrame")    #窗口标题
lf = LabelFrame(root, text="组1") #创建LabelFrame组件对象
lf.pack()
Button(lf, text="确定").pack(side=LEFT)  #确定按钮，左停靠
Button(lf, text="取消").pack(side=LEFT)  #取消按钮，左停靠
root.mainloop()
