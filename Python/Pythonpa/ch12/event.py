from tkinter import *    #导入tkinter模块所有内容
root = Tk()
def printEvent(event):    #事件处理函数
    print('当前坐标位置：',event.x, event.y)
root.bind('<Button-1>',printEvent)  #单击鼠标左键
root.mainloop()
