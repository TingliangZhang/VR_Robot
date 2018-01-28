def my_max(a, b, *c): #求若干数中的最大值
    max_value = a  #假设第一个数为最大值
    if max_value < b: #如果最大值小于b，则b为最大值
        max_value = b
    for n in c:      #循环迭代c中每个元素n，如果最大值小于n，则n为最大值
        if max_value < n:
            max_value = n
    return max_value  #利用return语句返回最大值
#测试代码
print(my_max(1, 2))         #求(1, 2)中的最大值
print(my_max(1, 7, 11, 2, 5))  #求(1, 7, 11, 2, 5)中的最大值
