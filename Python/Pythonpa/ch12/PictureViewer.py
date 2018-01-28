import tkinter as tk, os       #导入tkinter模块
class Application(tk.Frame):  #定义GUI应用程序类，派生于Frame类
    def __init__(self, master=None):       #构造函数，master为父窗口
        self.files = os.listdir(r'c:\pythonpa\images\gif') #获取图像文件名列表
        self.index = 0               #图片索引，初始显示第1张图片
        self.img = tk.PhotoImage(file=r'c:\pythonpa\images\gif' + '\\' + self.files[self.index])
        tk.Frame.__init__(self, master) #调用父类的构造函数
        self.pack()        #调用组件的pack方法，调整其显示位置和大小
        self.createWidgets() #调用对象方法，创建子组件
    def createWidgets(self):  #对象方法：创建子组件
        self.lblImage = tk.Label(self, width=300, height=300) #创建Label组件，显示图片
        self.lblImage['image'] = self.img #显示第1张图片
        self.lblImage.pack()          #调用组件的pack方法，调整其显示位置和大小
        self.f = tk.Frame()           #创建窗口框架
        self.f.pack()
        self.btnPrev = tk.Button(self.f, text='上一张', command=self.prev) #创建按钮组件
        self.btnPrev.pack(side=tk.LEFT) 
        self.btnNext = tk.Button(self.f, text='下一张', command=self.next) #创建按钮组件
        self.btnNext.pack(side=tk.LEFT) 
    def prev(self):         #定义事件处理程序
        self.showfile(-1)   #显示上一张图片
    def next(self):         #定义事件处理程序
        self.showfile(1)    #显示下一张图片
    def showfile(self, n):    #显示图片
        self.index += n
        if self.index < 0: self.index = len(self.files) - 1   #循环显示最后1张
        if self.index > len(self.files) - 1: self.index = 0   #循环显示第1张
        self.img = tk.PhotoImage(file=r'c:\pythonpa\images\gif' + '\\' + self.files[self.index])
        self.lblImage['image'] = self.img
root = tk.Tk()                #创建1个Tk根窗口组件root
root.title('简易图片浏览器')    #设置窗口标题
app = Application(master=root)  #创建Application的对象实例
app.mainloop()  #调用组件的mainloop方法，进入事件循环
