import sys
filename = sys.argv[0]  #所读取并输出的就是本程序文件type_file_with.py
line_no=0            #统计行号
with open(filename, 'r', encoding='utf8') as f:  #使用with语句实现上下文管理协议
    for line in f:
        line_no += 1         #行号计数
        print(line_no, ":", line)  #输出行号和该行内容
f.close()

