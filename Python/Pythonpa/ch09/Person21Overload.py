class Person21:                #定义类Person21
    def say_hi(self, name=None): #定义方法say_hi
        self.name = name #把参数name赋值给self.name，即成员变量name（域）
        if name==None: print('您好! ')
        else: print('您好, 我叫', self.name)
p21 = Person21()        #创建对象
p21.say_hi()            #调用对象的方法，无参数
p21.say_hi('威尔逊')     #调用对象的方法，带参数
