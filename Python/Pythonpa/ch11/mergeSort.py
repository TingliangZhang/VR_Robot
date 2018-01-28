def merge(left, right):    #合并两个列表
    merged = []
    i, j = 0, 0         #i和j分别作为left和right的下标
    left_len, right_len = len(left), len(right)  #分别获取左右子列表的长度
    while i < left_len and j < right_len:      #循环归并左右子列表元素
        if left[i] <= right[j]:
            merged.append(left[i])        #归并左子列表元素
            i += 1
        else:
            merged.append(right[j])       #归并右子列表元素
            j += 1
    merged.extend(left[i:])                #归并左子列表剩余元素
    merged.extend(right[j:])               #归并右子列表剩余元素
    print(left,right,merged)               #跟踪调试
    return merged                       #返回归并好的列表
def mergeSort(a):            #归并排序
    if len(a) <= 1:           #空或者只有1个元素，直接返回列表
        return a
    mid = len(a) // 2         #列表中间位置
    left = mergeSort(a[:mid])  #归并排序左子列表
    right = mergeSort(a[mid:]) #归并排序右子列表
    return merge(left, right)   #合并排好序的左右两个子列表
def main():
    a = [59,12,77,64,72,69,46,89,31,9]
    a1 = mergeSort(a)
    print(a1)
if __name__ == '__main__': main()
