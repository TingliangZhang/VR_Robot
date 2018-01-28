try:
    f = open("testfile.txt", "w")
    f.write("这是一个测试文件，用于测试异常!!")
    f1 = open("testfile1.txt", "r")
except IOError:
    print("没有找到文件或读取文件失败")
else:
    print("文件写入成功！")
finally:
    f.close()

