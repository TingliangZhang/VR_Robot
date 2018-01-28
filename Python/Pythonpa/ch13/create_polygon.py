from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=250, height=70); c.pack() #创建并显示Canvas
c.create_polygon(35,10,10,60,60,60,fill='white',outline='black') #黑边等腰三角形
c.create_polygon(70,10,120,10,120,60,fill='white',outline='black')#黑边直角三角形
c.create_polygon(130,10,180,10,180,60,130,60)             #黑色填充的正方形
c.create_polygon(190,10,240,10,190,60,240,60,fill='white',outline='black')#对顶三角形
