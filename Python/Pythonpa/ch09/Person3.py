class Person3: 
    count = 0   #定义属性count，表示计数
    name = "Person"   #定义属性name1，表示名称
#测试代码
Person3.count += 1
print(Person3.count)
print(Person3.name)
p1 = Person3()
p2 = Person3()
print((p1.name, p2.name))
Person3.name = "雇员"
print((p1.name, p2.name))
p1.name = "员工" #通过实例对象访问，则属于该实例的实例属性
print((p1.name, p2.name))
