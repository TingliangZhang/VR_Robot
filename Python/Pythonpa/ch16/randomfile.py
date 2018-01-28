import os
f=open('data.dat', 'w+b')    #创建或打开文件data.dat
f.seek(0)                #定位到开始位置
f.write(b'Hello')         #写入字节数据
f.write(b'World')         #写入字节数据
f.seek(-5, os.SEEK_END) #定位到结束位置倒数第5个位置
b = f.read(5)             #读取5个字节
print(b)                 #输出：b'World'
