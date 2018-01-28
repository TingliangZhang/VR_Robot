#chapter03\continue.py
num = 0; scores = 0;  #初始化学生人数和成绩和
while True:
    s = input('请输入学生成绩（按Q或q结束）：')
    if s.upper() == 'Q':
        break
    if float(s) < 0:   #成绩必须>=0
        continue
    num += 1       #统计学生人数
    scores += float(s) #成绩和
print('学生人数为：{0}，平均成绩为：{1}'.format(num,scores / num))
