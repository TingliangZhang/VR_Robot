import sys
filename = sys.argv[0]   #所读取并输出的就是本程序文件type_file.py
f=open(filename, 'r', encoding='utf-8')    #打开文件
line_no=0                                 #统计行号
while True:
    line_no += 1         #行号计数
    line = f.readline()  #读取行信息
    if line:  
        print(line_no, ":", line)  #输出行号和该行内容
    else:  
        break
f.close()             #关闭打开的文件

