#chapter03\for_else.py
hobbies = ""
for i in range(1, 3 + 1):
    s = input('请输入爱好之一（最多三个，按Q或q结束）：')
    if s.upper() == 'Q':
        break
    hobbies += s + ' '
else:
    print('您输入了三个爱好。')
print('您的爱好为：', hobbies)
