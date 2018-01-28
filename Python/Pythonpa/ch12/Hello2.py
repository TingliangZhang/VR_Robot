import tkinter as tk        #导入tkinter模块
class Application(tk.Frame): #定义GUI应用程序类，派生于Frame类
    def __init__(self, master=None):   #构造函数，master为父窗口
        tk.Frame.__init__(self, master) #调用父类的构造函数
        self.pack() #调用组件的pack方法，调整其显示位置和大小
        self.createWidgets()         #调用对象方法，创建子组件
    def createWidgets(self):          #对象方法：创建子组件
        self.btnSayHi = tk.Button(self) #创建按钮组件btnSayHi
        self.btnSayHi["text"] = "Hello" #设置显示文本属性
        self.btnSayHi["command"] = self.sayHi #设置命令属性，绑定事件处理程序
        self.btnSayHi.pack()     #调用组件的pack方法，调整其显示位置和大小
        #创建按钮组件btnQuit，其显示文本为"Quit"，命令事件处理程序为root.destroy
        self.btnQuit = tk.Button(self, text="Quit", command=root.destroy)
        self.btnQuit.pack()      #调用组件的pack方法，调整其显示位置和大小
    def sayHi(self):            #定义事件处理程序
        tk.messagebox.showinfo("Message","Hello, world!") #弹出消息框
root = tk.Tk()                 #创建1个Tk根窗口组件root
app = Application(master=root)  #创建Application的对象实例
app.mainloop()               #调用组件的mainloop方法，进入事件循环
