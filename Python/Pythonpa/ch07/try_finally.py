try:
    f = open('mytext.txt', 'w') #打开要写入的文件
    while True:
        s = input('请输入字符串（按Q结束）：')
        if s.upper() == 'Q': break
        f.write(s + '\n')
except KeyboardInterrupt:
    print('程序中断！（Ctrl-C）')
finally:
    f.close()
