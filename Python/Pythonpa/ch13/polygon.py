import turtle
def draw_polygon(sides, side_len): #绘制指定边长度的多边行
    for i in range(sides):
        turtle.forward(side_len)  #绘制边长
        turtle.left(360.0/sides)   #旋转角度
def main():
    for i in range(3,11):  #绘制三角形、正方形、正五边形、……、正十边形
        step = 50      #边长（海龟步长）为50
        draw_polygon(i, step) #绘制多边形
if __name__ == '__main__': main()
