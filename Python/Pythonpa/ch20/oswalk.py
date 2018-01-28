import re, os, os.path
def ls_py(top):
    for (dirname, subdirs, files) in os.walk(top):
        print('[' + dirname + ']')
        for fname in files:
            print(os.path.join(dirname, fname))
#测试代码
if __name__=='__main__':
    path1 = r'c:\pythonpa\ch17'
    ls_py(path1)
