a=[]  #初始化列表
x=float(input("请输入一个实数，输入-1终止："))
while x != -1:
    a.append(x)  #将所输入的实数添加到列表中
    x=float(input("请输入一个实数，输入-1终止："))
print("计数：", len(a))  #列表长度即为实数个数
print("求和：", sum(a))  #列表中各元素求和
print("平均值：", sum(a)/len(a)) #列表中各元素求平均值
