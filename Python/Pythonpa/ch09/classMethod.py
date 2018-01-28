class Foo:
    classname = "Foo"
    def __init__(self, name):
        self.name = name    
    def f1(self): #实例方法  
        print(self.name)  
    @staticmethod  
    def f2():     #静态方法  
        print("static")  
    @classmethod  
    def f3(cls): #类方法  
        print(cls.classname)  
#测试代码
f = Foo("李")
f.f1()
Foo.f2()
Foo.f3()
