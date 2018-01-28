from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=250, height=70); c.pack() #创建并显示Canvas
c.create_line(10,10,60,60,arrow=BOTH,arrowshape=(3,5,4))  #双向箭头
c.create_line(70,10,95,10,120,60)                        #折线
c.create_line(130,10,180,10,130,60,180,60,width=10,arrow=BOTH) #Z字型双向箭头
c.create_line(190,10,240,10,190,60,240,60,width=10,joinstyle=MITER) #Z字型
