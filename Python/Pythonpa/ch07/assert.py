a = int(input("请输入整数a："))
b = int(input("请输入整数b："))
assert b != 0, '除数不能为0'
c = a / b
print(a, '/', b, '=', c)
