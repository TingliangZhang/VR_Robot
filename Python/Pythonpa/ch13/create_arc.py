from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=250, height=70); c.pack() #创建并显示Canvas
c.create_arc(10,10,60,60, style=PIESLICE) #绘制PIESLICE样式圆弧
c.create_arc(70,10,120,60, style=CHORD) #绘制CHORD样式圆弧
c.create_arc(130,10,180,60, style=ARC)   #绘制ARC样式圆弧
for i in range(0, 360, 60):   #绘制菊花瓣蓝色边框红色填充的图形
    c.create_arc(190,10,240,60,fill='red',outline='blue',start=i,extent=30)
