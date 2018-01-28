import global_variable  #导入全局变量定义
def tax(x):            #根据税率常量20%计算纳税值
    return x * global_variable.TAX2
#测试代码
a = [1000, 1200, 1500, 2000]
for i in a:           #计算并打印4笔数据的纳税值
    print(i, tax(i))

