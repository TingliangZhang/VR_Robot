with open(r'c:\pythonpa\data1.txt', 'w') as f:
    f.write('123\n') #写入字符串
    f.write('abc\n') #写入字符串
    f.writelines(['456\n', 'def\n']) #写入字符串
