import sys
def harmonic(n): #计算n阶调和数（1 + 1/2 + 1/3 + … + 1/n）
    total = 0.0
    for i in range(1, n+1):
        total += 1.0 / i
    return total
n = int(sys.argv[1]) #从命令行第一个参数中获取调和数阶数
for i in range(1, n+1): #输出前n个调和数的值
    print(harmonic(i))

