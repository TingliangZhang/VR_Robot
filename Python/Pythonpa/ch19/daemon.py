import threading, time
class MyThread(threading.Thread):          #继承threading.Thread
    def __init__(self, interval):            #构造函数
        threading.Thread.__init__(self)     #调用父类构造函数
        self.interval = interval            #对象属性
    def run(self):                       #定义run方法
       t = threading.current_thread()      #获取当前线程
       print('线程' + t.name + '开始')
       time.sleep(self.interval)            #延迟self.interval秒
       print('线程' + t.name + '结束')
class MyThreadDaemon(threading.Thread):  #继承threading.Thread
    def __init__(self, interval):           #构造函数
        threading.Thread.__init__(self)   #调用父类构造函数
        self.interval = interval          #对象属性
    def run(self):                     #定义run方法
       t = threading.current_thread()    #获取当前线程
       print('线程' + t.name + '开始')
       while True:
           time.sleep(self.interval)     #延迟self.interval秒
           print('daemon线程' + t.name + '正在运行')
       print('线程' + t.name + '结束')
def test():
    print('主线程开始') 
    t1 = MyThread(5)              #创建线程对象
    t2 = MyThreadDaemon(1)       #创建线程对象
    t1.name = 't1'; t2.name = 't2'     #设置线程名称
    t2.daemon = True             #设置为daemon
    t1.start()                    #启动线程
    t2.start()
    print('主线程结束')     
if __name__=='__main__':
    test()
