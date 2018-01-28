a = (44, 78, 90, -80, 55)
sum = 0
try:
    for i in data:
        if i < 0: raise ValueError(str(i)+"为负数")
        sum += i
    print('平均值=', average(data2))
except ValueError:
    print('数值不能为负')
except Exception:
    print('发生异常')

