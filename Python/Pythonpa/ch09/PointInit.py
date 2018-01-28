class Point: 
    def __init__(self, x = 0, y = 0): #构造函数
        self.x = x 
        self.y = y 
p1 = Point()                   #创建对象
print("p1({0},{1})".format(p1.x, p1.y))
p1 = Point(5, 5)               #创建对象
print("p1({0},{1})".format(p1.x, p1.y))
