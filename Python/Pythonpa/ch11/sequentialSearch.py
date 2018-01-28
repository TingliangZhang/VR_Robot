def sequentialSearch(alist, item): #顺序查找法
    pos = 0            #初始查找位置
    found = False       #未找到数据对象
    while pos < len(alist) and not found: #列表未结束并且还未找到则一直循环
        if alist[pos] == item:         #找到匹配对象，返回True
            found = True
        else:                      #否则查找位置+1
            pos = pos+1
    return found
def main():
    testlist = [1, 3, 33, 8, 37, 29, 32, 15, 5]   #测试数据列表
    print(sequentialSearch(testlist, 3))      #查找数据3
    print(sequentialSearch(testlist, 13))     #查找数据13
if __name__=='__main__': main()
