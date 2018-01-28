import os, shutil
def get_term_size_test():
    sz = shutil.get_terminal_size()
    print('窗口大小：', sz)
    for i in range(sz.lines):
        print('*' * sz.columns)
if __name__ == '__main__':
    get_term_size_test()
