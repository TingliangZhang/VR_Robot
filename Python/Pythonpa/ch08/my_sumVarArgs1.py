def my_sum3(a, b, *c): #各数字累加和
    total = a + b
    for n in c:
       total = total + n
    return total
print(my_sum3(1, 2))                 #计算1+2
print(my_sum3(1, 2, 3, 4, 5))        #计算1+2+3+4+5
print(my_sum3(1, 2, 3, 4, 5, 6, 7))  #计算1+2+3+4+5+6+7
