import random
def randomarray(n): #生成由n个随机数构成的列表
    a = []
    for i in range(n):
        a.append(random.random())
    return a
#测试代码
b=randomarray(5)     #生成由5个随机数构成的列表
for i in b: print(i) #输出列表中每个元素




