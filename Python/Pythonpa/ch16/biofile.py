from io import BytesIO
f = BytesIO()
f.write('中文'.encode('utf-8'))
f.seek(0)            #定位到开始位置
b=f.read()           #读取文件内容
print(b)             #显示文件内容
print(f.getvalue())    #显示文件内容
