def insertSort(a):
    for i in range(1, len(a)):            #外循环（1~N-1）
        j = i
        while (j > 0) and (a[j] < a[j-1]):  #内循环
            a[j], a[j-1] = a[j-1], a[j]    #元素交换
            j -= 1                  #继续循环
        #print(a) #跟踪调试
        
def main(): 
    a = [59,12,77,64,72,69,46,89,31,9]
    insertSort(a)
    print(a)
if __name__ == '__main__': main()
