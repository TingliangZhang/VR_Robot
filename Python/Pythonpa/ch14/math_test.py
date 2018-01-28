import math
#三角形三边a、b、c，必须满足：a>0 and b>0 and c>0 and a+b>c and a+c>b and b+c>a
a=int(input("请输入边长a："))
b=int(input("请输入边长b："))
c=int(input("请输入边长c："))
if (a>0 and b>0 and c>0 and a+b>c and a+c>b and b+c>a):
    p = (a + b + c) / 2                  #周长的一半
    area = math.sqrt(p * (p - a) * (p - b) * (p - c))  #面积
    perimeter = a + b + c                     #周长
    height_a = 2 * area / a      #边长a所对应的高
    max_side = max(a, b, c)     #最长边长
    min_side = min(a, b, c)     #最短边长
    print("三角形的三条边为：{0}、{1}和{2}".format(a, b, c))
    print("三角形的面积为：{0:.2f}".format(area))
    print("三角形的周长为：{0:.2f}".format(perimeter))
    print("边长A对应的高为：{0:.2f}".format(height_a))
    print("三角形的最长的边为：{0:.2f}".format(max_side))
    print("三角形的最短的边为：{0:.2f}".format(min_side))
else:
    print("三条边：{0}、{1}和{2}，不能构成三角形".format(a, b, c))
