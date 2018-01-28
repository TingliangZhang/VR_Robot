from tkinter import *          #导入tkinter模块所有内容
root = Tk();root.title("登录")    #窗口标题
root['width']=200; root['height']=80              #窗口宽度、高度
Label(root, text="用户名", width=6).place(x=1, y=1) #用户名标签，绝对坐标(1,1)
Entry(root, width=20).place(x=45, y=1)            #用户名文本框，绝对坐标(45,1)
Label(root, text="密  码",width=6).place(x=1, y=20) #密码标签，绝对坐标(1,20)
Entry(root, width=20,show="*").place(x=45, y=20)  #密码文本框，绝对坐标(45,20)
Button(root, text="登录", width=8).place(x=40, y=40) #登录按钮，绝对坐标(40,40)
Button(root, text="取消", width=8).place(x=110, y=40)#取消按钮，绝对坐标(110,40)
root.mainloop()

