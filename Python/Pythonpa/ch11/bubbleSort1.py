def bubbleSort(a):
    for i in range(len(a)-1,-1,-1):
        for j in range(i):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
        print(a)    #跟踪调试
def main():
    a = [2,97,86,64,50,80,3,71,8,76]
    bubbleSort(a)
    print(a)
if __name__ == '__main__': main()
