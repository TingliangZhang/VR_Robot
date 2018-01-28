class Person5:             #定义类Person5
    def __init__(self, name): #__init__方法
        self.name = name #把参数name赋值给self.name，即成员变量name（域）
    def say_hi(self):     #定义类Person的函数sayHi
        print('您好, 我叫', self.name)
p5 = Person5('Helen')    #创建对象
p5.say_hi()            #调用对象的方法
