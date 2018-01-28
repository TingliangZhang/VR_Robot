from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=280, height=70); c.pack() #创建并显示Canvas
c.create_oval(10,10,60,60,fill='red') #红色填充椭圆
c.create_oval(70,10,120,60,fill='red',outline='blue',width=5) #红色填充蓝色边框宽度5的椭圆
c.create_oval(130,25,180,45,dash=(4,))       #虚线椭圆
c.create_oval(190,10,270,50,dash=(4,),width=2) #宽度为2的虚线椭圆
