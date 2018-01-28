class Person4:            #定义类Person
    def say_hi(self, name): #定义方法say_hi
        self.name = name #把参数name赋值给self.name，即成员变量name（域）
        print('您好, 我叫', self.name)
p4 = Person4()    #创建对象
p4.say_hi('Alice')  #调用对象的方法
