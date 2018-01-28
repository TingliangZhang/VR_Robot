def max1(alist):       #查找最大值
    pos = 0          #初始查找位置
    iMax = alist[0]    #假设第一个值最大
    while pos < len(alist):     #在列表中循环
        if alist[pos] > iMax:  #如果列表当前值大于最大值iMax
            iMax = alist[pos]  #则当前值为最大值iMax
        pos = pos+1          #查找位置+1
    return iMax              #返回最大值
def min1(alist):            #查找最小值
    iMin = alist[0]         #假设第一个值最小
    for item in alist:        #对于列表中每个数值
        if item < iMin:     #如果列表当前值小于最小值iMin
            iMin = item   #则当前值为最小值iMin
    return iMin           #返回最小值
def main():
    testlist = [1, 3, 33, 8, 37, 29, 32, 15, 5]   #测试数据列表
    print("最大值=",max1(testlist))               #查找并打印列表中最大值
    print("最小值=",min1(testlist))               #查找并打印列表中最小值
if __name__=='__main__': main()
