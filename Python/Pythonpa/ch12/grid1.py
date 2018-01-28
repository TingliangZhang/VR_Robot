from tkinter import *          #导入tkinter模块所有内容
root = Tk(); root.title("登录")   #窗口标题
Label(root, text="用户名").grid(row=0, column=0) #用户名标签放置第0行第0列
Entry(root).grid(row=0, column=1, columnspan=2) #用户名文本框放置第0行第1列，跨2列
Label(root, text="密  码").grid(row=1, column=0) #密码标签放置第1行第0列
Entry(root, show="*").grid(row=1, column=1, columnspan=2) #密码文本框放置第1行第1列，跨2列
Button(root, text="登录").grid(row=3, column=1, sticky=E) #登录按钮右侧贴紧
Button(root, text="取消").grid(row=3, column=2, sticky=W) #取消按钮左侧贴紧
root.mainloop()
