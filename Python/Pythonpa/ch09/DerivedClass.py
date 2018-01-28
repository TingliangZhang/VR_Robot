class Person:                 #基类
    def __init__(self, name, age): #构造函数
        self.name = name     #姓名
        self.age = age        #年龄
    def say_hi(self):         #定义基类方法say_hi
        print('您好, 我叫{0}, {1}岁'.format(self.name,self.age))
class Student(Person):         #派生类
    def __init__(self, name, age, stu_id): #构造函数
        Person.__init__(self, name, age) #调用基类构造函数
        self.stu_id = stu_id    #学号
    def say_hi(self):          #定义派生类方法say_hi
        Person.say_hi(self)    #调用基类方法say_hi
        print('我是学生, 我的学号为：', self.stu_id)
p1 = Person('张王一', 33)            #创建对象
p1.say_hi()
s1 = Student('李姚二', 20, '2013101001') #创建对象
s1.say_hi()
