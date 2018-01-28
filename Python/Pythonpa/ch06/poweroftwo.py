import sys
n = int(sys.argv[1])   #从命令行第一个参数中获取n的值
power = 1              #2的0~n次幂赋初值
i = 0                  #计数赋初值
f = open('out.log', 'w') #指定标准输出重定向到文件out.log中
sys.stdout = f
while i <= n:
    print(str(i), ' ', str(power)) #输出0~n以及2的0~n次幂的列表
    power = 2 * power              #计算2的0~n次幂
    i = i + 1                      #计数加1
sys.stdout = sys.__stdout__
print('done!')
