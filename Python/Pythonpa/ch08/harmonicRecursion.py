def harmonic(n):
    if n == 1: return 1.0          #终止条件
    return harmonic(n-1) + 1.0/n   #递归步骤
#测试代码
for i in range(1,10): #输出1~9阶的调和数
    print('H', i, ' =', harmonic(i))

