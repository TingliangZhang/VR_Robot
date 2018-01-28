def binarySearch(key, a): #二分查找法的非递归实现
    low = 0             #左边界
    high = len(a) - 1      #右边界
    while low <= high:    #左边界小于等于右边界，则循环
        mid = (low + high) // 2  #计算中间位置
        if a[mid] < key:        #中间位置项目小于查找关键字
            low = mid + 1     #调整左边界（在后一子表查找）
        elif a[mid] > key:      #中间位置项目大于查找关键字
            high = mid - 1     #调整右边界（在前一子表查找）
        else:                 #中间位置项目等于查找关键字
            return mid        #查找成功，返回下标位置
    return -1           #查找不成功（不存在关键字），返回-1
def main():
    a = [1,13,26,33,45,55,68,72,83,99]
    print("关键字位于列表索引",binarySearch(33, a)) #二分查找关键字33
    print("关键字位于列表索引",binarySearch(58, a)) #二分查找关键字58
if __name__ == '__main__': main()
