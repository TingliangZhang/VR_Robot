import time
def test():
    sum = 0   
    for i in range(0,9999999):
        sum += i 
    return sum
if __name__=='__main__':
    t1 = time.monotonic() #单向时钟
    print(test())     
    t2 = time.monotonic() #单向时钟
    print('运行时间：', t2-t1)
