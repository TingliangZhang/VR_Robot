def getValue(b,r,n):          #创建函数对象getValue
    v = b*((1+r)**n)        #计算最终收益v
    return v               #使用return返回值
total = getValue(1000,0.05,5)  #调用函数getValue
print(total)                 #打印结果

