f1 = 1; f2 = 1
for i in range(1, 11):
    print(str.format("{0:6}{1:6}", f1, f2), end=" ") #输出2个数，每个占6位
    if i % 2 == 0: print()             #每行输出2次，即2*2=4个数
    f1 += f2; f2 += f1
input()
