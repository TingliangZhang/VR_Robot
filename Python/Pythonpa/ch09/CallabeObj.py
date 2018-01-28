class GDistance:       #类：自由落体距离
    def __init__(self, g): #构造函数
        self.g = g 
    def __call__(self, t): #自由落体下落距离
        return (self.g*t**2)/2
#测试代码
if __name__ == '__main__':
    e_gdist = GDistance(9.8) #地球上的重力加速度
    for t in range(11):      #自由落体0~10秒的下落距离
        print(format(e_gdist(t), "0.2f"),end=' ') #调用可调用对象e_gdist
