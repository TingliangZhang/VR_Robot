def selectionSort(a):
    for i in range(0, len(a)):         #外循环（0~N-1）
        m = i                    #当前位置下标
        for j in range(i + 1, len(a)):   #内循环
            if a[j] < a[m]:          #查找最小值的位置
                m = j
        a[i], a[m] = a[m], a[i]       #元素交换
        #print(a) #跟踪调试
def main():
    a = [59,12,77,64,72,69,46,89,31,9]
    selectionSort(a)
    print(a)
if __name__ == '__main__': main()
