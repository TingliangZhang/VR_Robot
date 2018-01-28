#chapter03\break.py
while True:
    s = input('请输入字符串（按Q或者q结束）：')
    if s.upper() == 'Q':
        break
    print('字符串的长度为：', len(s))
