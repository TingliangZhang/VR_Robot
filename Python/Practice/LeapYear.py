import math
y=int(input("请输入年份："))
if(y%400==0):
    print("是闰年")
elif(y%4!=0):
        print("不是闰年")
elif(y%100==0):
            print("不是闰年")
else:
                print("是闰年")
input()
