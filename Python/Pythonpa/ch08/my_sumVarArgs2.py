def my_sum4(a, b, *c, **d): #各数字累加和
    total = a + b
    for n in c:             #元组中各元素累加和
       total = total + n
    for key in d:           #字典中各元素累加和
        total = total + d[key]
    return total
print(my_sum4(1, 2)) #计算1+2
print(my_sum4(1, 2, 3, 4, 5))  #计算1+2+3+4+5
print(my_sum4(1, 2, 3, 4, 5, male = 6, female = 7)) #计算1+2+3+4+5+6+7
