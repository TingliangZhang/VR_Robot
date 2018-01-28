PI = 3.14        #定义常量
def add(x, y):    #定义函数
    return x + y  #加
def sub(x, y):    #定义函数
    return x - y  #减
def mul(x, y):    #定义函数
    return x * y  #乘
def div(x, y):     #定义函数
    return x / y  #除
#测试代码
def main():
    print('123 + 456 =', add(123, 456))   #加
    print('123 - 456 =', sub(123, 456))   #减
    print('123 * 456 =', mul(123, 456))  #乘
    print('123 / 456 =', div(123, 456))   #除
if __name__ == '__main__': #如果独立运行时，则运行测试代码
    main()
