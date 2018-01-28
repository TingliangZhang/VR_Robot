import math
x=-1
y = math.sin(x) + 2 * math.sqrt(x + math.exp(4)) - math.pow(x + 1, 3)
if (x<0):
   y = math.log(-5 * x) - math.fabs(x * x - 8 * x) / (7 * x) + math.e
print(y)
#或两句单分支语句：
if (x>=0):
   y = math.sin(x) + 2 * math.sqrt(x + math.exp(4)) - math.pow(x + 1, 3)
if (x<0):
   y = math.log(-5 * x) - math.fabs(x * x - 8 * x) / (7 * x) + math.e
print(y)
#（2）利用双分支结构实现
if (x>=0):
   y = math.sin(x) + 2 * math.sqrt(x + math.exp(4)) - math.pow(x + 1, 3)
else:
   y = math.log(-5 * x) - math.fabs(x * x - 8 * x) / (7 * x) + math.e
print(y)
#（3）利用条件运算语句实现
y = (math.sin(x) + 2 * math.sqrt(x + math.exp(4)) - math.pow(x + 1, 3)) if ((x>=0)) else \
   (math.log(-5 * x) - math.fabs(x * x - 8 * x) / (7 * x) + math.e)
print(y)
