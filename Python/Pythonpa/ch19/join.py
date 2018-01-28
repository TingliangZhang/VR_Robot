import threading, time, random
class MyThread(threading.Thread):       #继承threading.Thread
    def __init__(self):                 #构造函数
        threading.Thread.__init__(self)  #调用父类构造函数
    def run(self):                    #定义run方法
       for i in range(5):
           time.sleep(1)                 #睡眠1秒
           t = threading.current_thread()   #获取当前线程
           print('{0} at {1}\n'.format(t.name, time.ctime()))#打印线程名、当前时间
       print('线程t1结束')
def test():
    t1 = MyThread()     #创建线程对象
    t1.name = 't1'        #设置线程名称
    t1.start()            #启动线程
    print('主线程开始等待线程(t1)2s'); t1.join(2)
    print('主线程等待线程(t1)2s结束')
    print('主线程开始等待线程结束'); t1.join()
    print('主线程结束')
if __name__=='__main__':
    test()
