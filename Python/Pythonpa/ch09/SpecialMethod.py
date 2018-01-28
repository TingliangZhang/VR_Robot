class Person:
    def __init__(self, name, age): #构造函数
        self.name = name
        self.age = age
    def __str__(self):          #特殊方法，输出成员变量
        return '{0}, {1}'.format(self.name,self.age)
#测试代码
p1 = Person('张三', 23)
print(p1)
