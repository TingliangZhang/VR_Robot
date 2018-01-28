from tkinter import *    #导入tkinter模块所有内容
root = Tk()            #创建1个Tk根窗口组件root
btnSayHi = Button(root)  #创建1个按钮组件btnSayHi，作为root的子组件
btnSayHi["text"]="Hello" #设置btnSayHi的text属性
btnSayHi.pack()        #调用组件的pack方法，调整其显示位置和大小
def sayHi(e):           #定义事件处理程序
    messagebox.showinfo("Message","Hello, world!") #弹出消息框
btnSayHi.bind("<Button-1>",sayHi)  #绑定事件处理程序，鼠标左键
root.mainloop()        #调用组件的mainloop方法，进入事件循环
