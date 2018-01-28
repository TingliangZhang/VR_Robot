x=-10
#方法一（多分支结构）：
if (x > 0): y = 1
elif (x == 0): y = 0
else: y = -1
print(y)
#方法二（if语句嵌套结构）：
if (x >= 0):
    if (x > 0): y = 1
    else: y = 0
else: y = -1
print(y)
#方法三：
y = 1
if (x != 0):
    if (x < 0): y = -1
else: y = 0
print(y)
#方法四：
y = 1
if (x != 0):
    if (x < 0): y = -1
    else: y = 0
print(y)
