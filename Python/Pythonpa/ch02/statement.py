import math                          #import语句，用于导入math模块
r = float(input("请输入圆的半径r："))   #赋值语句。输入圆的半径r，并转换为float数据类型
p = 2* math.pi*r                     #赋值语句。计算圆的周长
s = math.pi* r**2                    #赋值语句。计算圆的面积
print("圆的周长为：", p)  #表达式语句。输出圆的周长
print("圆的面积为：", s)   #表达式语句。输出圆的面积
#input()
