import calendar
y=2016
#方法一。使用一个逻辑表达式包含所有的闰年条件
if ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0):
    print("是闰年")
else: print("不是闰年")
#方法二。使用嵌套的if语句，相关语句如下：
if (y % 400 == 0): print("是闰年")
else:
    if (y % 4 == 0):
        if (y % 100 == 0): print("不是闰年")
        else: print("是闰年")
    else: print("不是闰年")
#方法三。使用if-elif语句，相关语句如下：
if (y % 400 == 0): print("是闰年")
elif (y % 4 != 0): print("不是闰年")
elif (y % 100 == 0): print("不是闰年")
else: print("是闰年")
#方法四。使用calendar模块的isleap函数来判断闰年，相关语句如下：
if (calendar.isleap(y)): print("是闰年")
else: print("不是闰年")
