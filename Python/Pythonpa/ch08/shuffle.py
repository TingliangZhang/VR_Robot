def shuffle(a):
    n = len(a)          #获取列表a的长度n
    for i in range(n):  #0~n-1进行循环迭代
        r = random.randrange(i, n) #取[i,n)之间的随机整数
        exchange(a, i, r)          #交换列表a中下标分别为i和r的元素值


    




