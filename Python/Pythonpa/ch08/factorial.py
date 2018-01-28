def factorial(n):
    if n == 1: return 1
    return n * factorial(n - 1)
#测试代码
for i in range(1,10): #输出1~9的阶乘
    print(i,'! =', factorial(i))
