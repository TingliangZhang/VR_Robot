class A:
    __name = 'class A'   #私有类属性
    def get_name():
        print(A.__name) #在类方法中访问私有类属性
#测试代码
A.get_name()
A.__name          #导致错误，不能直接访问私有属性
