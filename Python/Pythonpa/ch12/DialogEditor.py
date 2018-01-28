import tkinter as tk #导入tkinter模块
import tkinter.scrolledtext as tst
class Application(tk.Frame): #定义GUI应用程序类，派生于Frame类
    def __init__(self, master=None): #构造函数，master为父窗口
        tk.Frame.__init__(self, master) #调用父类的构造函数
        self.grid()        #调用组件的pack方法，调整其显示位置和大小
        self.createWidgets() #调用对象方法，创建子组件
    def createWidgets(self): #对象方法：创建子组件
        self.textEdit = tst.ScrolledText(self, width=80, height=20) #创建Text组件
        self.textEdit.grid(row=0, column=0, rowspan=6) #文本框置于0行0列
        self.btnOpen = tk.Button(self, text='打开', command=self.funcOpen) #创建按钮组件
        self.btnOpen.grid(row=1, column=1)  #打开按钮置于1行1列
        self.btnSave = tk.Button(self, text='保存', command=self.funcSave) #创建按钮组件
        self.btnSave.grid(row=2, column=1)  #保存按钮置于2行1列
        self.btnColor = tk.Button(self, text='颜色', command=self.funcColor) #创建按钮组件
        self.btnColor.grid(row=3, column=1)  #颜色按钮置于3行1列
        self.btnQuit = tk.Button(self, text='退出', command=self.funcQuit) #创建按钮组件
        self.btnQuit.grid(row=4, column=1)  #退出开按钮置于4行1列
    def funcOpen(self): #定义事件处理程序：打开文件
        self.textEdit.delete(1.0, tk.END) #清空Text组件的内容
        fname = tk.filedialog.askopenfilename(filetypes=[('Python源文件','.py')])
        with open(fname, 'r', encoding= 'utf-8') as f1: #打开文件
            str1 = f1.read() #读入文件内容
        self.textEdit.insert(0.0, str1) #插入内容到Text组件
    def funcSave(self): #定义事件处理程序：保存文件
        str1 = self.textEdit.get(1.0, tk.END)
        fname = tk.filedialog.asksaveasfilename(filetypes=[('Python源文件','.py')])
        with open(fname, 'w', encoding= 'utf-8') as f1: #打开文件
            f1.write(str1)
    def funcColor(self): #定义事件处理程序：设置颜色
        t, c = tk.colorchooser.askcolor(title='askcolor')
        self.textEdit.config(bg=c)
    def funcQuit(self):    #定义事件处理程序：退出程序
        root.destroy()    #退出程序
root = tk.Tk()            #创建1个Tk根窗口组件root
root.title('简易文本编辑器') #设置窗口标题
app = Application(master=root) #创建Application的对象实例
app.mainloop()  #调用组件的mainloop方法，进入事件循环
