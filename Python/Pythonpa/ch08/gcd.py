import sys
def gcd(p, q):  #使用递归函数计算p和q的最大公约数
    if q == 0: return p    #如果q=0，返回p
    return gcd(q, p % q)  #否则，递归调用gcd(q, p % q)
#测试代码
p = int(sys.argv[1])  #p=命令行第一个参数
q = int(sys.argv[2])  #q=命令行第一个参数
print(gcd(p, q))     #计算并输出p和q的最大公约数
