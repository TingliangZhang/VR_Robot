import functools
@functools.total_ordering
class Student:
    def __init__(self, firstname, lastname):  #姓和名
        self.firstname = firstname
        self.lastname = lastname
    def __eq__(self, other):     #判断姓名是否一致
        return ((self.lastname.lower(), self.firstname.lower()) ==
                (other.lastname.lower(), other.firstname.lower()))
    def __lt__(self, other):     #self姓名<other姓名
        return ((self.lastname.lower(), self.firstname.lower()) <
                (other.lastname.lower(), other.firstname.lower()))
#测试代码
if __name__ == '__main__':
    s1 = Student('Mary','Clinton')
    s2 = Student('Mary','Clinton')
    s3 = Student('Charlie','Clinton')
    print(s1==s2)
    print(s1>s3)
