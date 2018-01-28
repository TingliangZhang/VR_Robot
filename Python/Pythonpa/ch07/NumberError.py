class NumberError(Exception):  #自定义异常类，继承于Exception
    def __init__(self,data):
        Exception.__init__(self, data)
        self.data = data
    def __str__(self):        #重载__str__方法
        return self.data + ': 非法数值(< 0)'
def total(data):
    total = 0
    for i in data:
        if i < 0: raise NumberError(str(i))
        total += i
    return total
#测试代码
data1 = (44, 78, 90, 80, 55)
print('总计=', total(data1))
data2 = (44, 78, 90, -80, 55)
print('总计=', total(data2))
