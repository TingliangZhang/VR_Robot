import turtle
p = turtle.Turtle()   #创建海龟对象
p.color("red")      #设置绘制时画笔的颜色
p.pensize(3)       #定义绘制时画笔的线条宽度
turtle.speed(1)    #定义绘图的速度 
p.goto(0,0)        #移动海龟到坐标原点(0,0)
for i in range(4):    #绘出正方形的四条边
   p.forward(100)  #向前移动100
   p.right(90)      #向右旋转90度
