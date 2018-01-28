#chapter03\continue_div3.py
j = 0 #控制一行显示的数字个数
print('100~200之间不能被3整除的数为：')
for i in range(100, 200 + 1):
    if (i % 3 == 0): continue #跳过被3整除的数
    print(str.format("{0:<5}",i), end="")
    j += 1
    if (j % 10 == 0): print() #一行显示10个数后换行
