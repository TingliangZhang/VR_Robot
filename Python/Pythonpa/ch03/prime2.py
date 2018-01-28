#chapter03\prime2.py
import math
m = int(input("请输入一个整数(>1)："))
k = int(math.sqrt(m))
flag = True #先假设所输整数为素数
i = 2
while (i <= k and flag == True):
    if (m % i == 0): flag = False #可以整除，肯定不是素数，结束循环
    else: i += 1
if (flag == True): print(m, "是素数！")
else: print(m, "是合数！")
input()
