from tkinter import * #导入tkinter模块所有内容
root = Tk(); root.title("登录")  #窗口标题
f1 = Frame(root); f1.pack() #界面分为上下3个Frame，f1放置第1行标签和文本框
f2 = Frame(root); f2.pack() #f2放置第2行标签和文本框
f3 = Frame(root); f3.pack() #f3放置第3行2个按钮
Label(f1, text="用户名").pack(side=LEFT) #标签放置在f1中，左停靠
Entry(f1).pack(side=LEFT)       #单行文本框放置在f1中，左停靠
Label(f2, text="密  码").pack(side=LEFT) #标签放置在f2中，左停靠
Entry(f2, show="*").pack(side=LEFT) #单行文本框放置在f2中，左停靠
Button(f3, text="取消").pack(side=RIGHT) #按钮放置在f3中，右停靠
Button(f3, text="登录").pack(side=RIGHT) #按钮放置在f3中，右停靠
root.mainloop()
