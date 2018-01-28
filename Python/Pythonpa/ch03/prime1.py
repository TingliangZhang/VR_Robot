#chapter03\prime1.py
import math
m = int(input("请输入一个整数(>1)："))
k = int(math.sqrt(m))
for i in range(2, k + 2):
    if m % i == 0:
        break  #可以整除，肯定不是素数，结束循环
if i == k+1 : print(m, "是素数！")
else: print(m, "是合数！")

