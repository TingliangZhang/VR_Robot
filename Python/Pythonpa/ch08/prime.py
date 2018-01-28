def is_prime(n):
    if n < 2: return False  #如果n小于2，返回False
    i = 2
    while i*i <= n:
        #一旦n能够被2~ 中的任意整数整除，n就不是素数，返回False
        if n % i == 0: return False 
        i += 1
    return True
#测试代码
for i in range(100):  #判断并输出1~99中的素数，以空格分隔
    if is_prime(i):print(i, end=' ')

