from tkinter import *
import math
WIDTH = 510; HEIGHT = 210          #画布宽度、高度
ORIGIN_X = 2; ORIGIN_Y = HEIGHT / 2 #原点（X=2、Y=窗体左边中心）
SCALE_X = 40; SCALE_Y = 100       #X轴、Y轴的缩放倍数
END_ARC = 360 * 2                 #函数图形画多长
ox = 0; oy = 0; x = 0; y = 0             #坐标初始值
arc = 0                             #弧度
root = Tk()
c = Canvas(root,bg = 'white', width=WIDTH, height=HEIGHT);c.pack()#创建并显示Canvas
c.create_text(200, 20, text='y=sin(x)')           #绘制文字
c.create_line(0, ORIGIN_Y, WIDTH, ORIGIN_Y) #绘制Y纵轴
c.create_line(ORIGIN_X, 0, ORIGIN_X, HEIGHT)#绘制X横轴
for i in range(0, END_ARC+1, 10):               #绘制函数图形
    arc = math.pi * i * 2 / 360
    x = ORIGIN_X + arc * SCALE_X
    y = ORIGIN_Y - math.sin(arc) * SCALE_Y
    c.create_line(ox, oy, x, y)
    ox = x; oy = y
