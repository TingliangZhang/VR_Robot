EPSILON = 1e-15     #容差
a = float(input("请输入正实数a："))  #正实数a
t = a                #假设平方根t=a
while abs(t - a/t) > (EPSILON * t):
    t = (a/t + t) / 2.0  #将t和a/t的平均值赋值给t
print(t)             #输出a的平方根
