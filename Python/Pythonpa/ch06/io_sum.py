import sys
n = int(sys.argv[1])   #命令行第一个参数确认所需求和的整数个数n
sum = 0                #设置求和初始值=0
for i in range(n):
    number = int(input('请输入整数：')) #输入整数
    sum += number                     #整数加 
print('累计和为：', sum) #输出n个整数累计和
