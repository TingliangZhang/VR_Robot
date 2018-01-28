a = int(input("请输入第1个整数："))
b = int(input("请输入第2个整数："))
print(str.format("输入值：{0}, {1}", a, b))
if (a < b): 
    t = a
    a = b
    b = t
print(str.format("降序值：{0}, {1}", a, b)) 
