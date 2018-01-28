import tkinter as tk          #导入tkinter模块
def popup(event):           #事件处理函数
    menubar.post(event.x_root, event.y_root) #鼠标右键位置显示菜单
root = tk.Tk()               #创建1个Tk根窗口组件root
#创建菜单
menubar = tk.Menu(root)     #创建菜单
menubar.add_command(label="Font")
menuedit = tk.Menu(menubar, tearoff=0)
menubar.add_cascade(label="Edit", menu=menuedit)
menuedit.add_command(label="Copy")
menuedit.add_command(label="Cut")
menuedit.add_command(label="Paste")
#创建界面
textEdit = tk.Text(root, width=40, height=10)#创建Text组件
textEdit.pack()
root.bind('<Button-3>', popup)           #绑定事件
#附加主菜单到根窗口
root.mainloop() #调用组件的mainloop方法，进入事件循环
