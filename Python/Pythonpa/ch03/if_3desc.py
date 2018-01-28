#chapter03\if_3desc.py

a = int(input("请输入整数a："))
b = int(input("请输入整数b："))
c = int(input("请输入整数c："))
if (a < b): t = a; a = b; b = t
if (a < c): t = a; a = c; c = t
if (b < c): t = b; b = c; c = t
print("排序结果（降序）：", a, b, c)


input()
