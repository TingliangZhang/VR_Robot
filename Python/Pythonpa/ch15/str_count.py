s1 = input('请输入字符串：') #'The quick brown fox jumps over the lazy dog'
s2 = s1.upper()    #转换为大写
countall = len(s1)
counta=s2.count('A');counte=s2.count('E');counti=s2.count('I')
counto=s2.count('O');countu=s2.count('U')
print('所有字母的总数为：', countall)
print('元音字母出现的次数和频率分别为：')
print('A：{0}\t{1:2.2f}%'.format(counta, counta/countall * 100))
print('E：{0}\t{1:2.2f}%'.format(counte, counte/countall * 100))
print('I：{0}\t{1:2.2f}%'.format(counti, counti/countall * 100))
print('O：{0}\t{1:2.2f}%'.format(counto, counto/countall * 100))
print('U：{0}\t{1:2.2f}%'.format(countu, countu/countall * 100))
