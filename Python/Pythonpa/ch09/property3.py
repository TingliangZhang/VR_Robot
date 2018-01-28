class Person13:
    def __init__(self, name):
        self.__name = name
    def getname(self):
        return self.__name
    def setname(self, value):
        self.__name = value
    def delname(self):
        del self.__name
    name = property(getname, setname, delname, "I'm the 'name' property.")
#测试代码
p = Person13('爱丽丝');print(p.name)
p.name = '罗伯特'; print(p.name)
