import turtle
p = turtle.Turtle()  #创建海龟对象
p.speed(0)        #定义绘图的速度（“fastest”或者0均表示最慢）
colors = ["red", "blue", "green", "yellow"] #红、蓝、绿、黄四种颜色
for i in range(100):         #i=0~99
    p.pencolor(colors[i%4]) #设置画笔颜色（红或蓝或绿或黄）
    p.circle(i)            #画圆
    p.left(91)            ##向左旋转91度
