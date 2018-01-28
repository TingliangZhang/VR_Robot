import threading, time, random
class MyThread(threading.Thread):       #继承threading.Thread
    def __init__(self, interval):          #构造函数
        threading.Thread.__init__(self)  #调用父类构造函数
        self.interval = interval         #对象属性
    def run(self):                    #定义run方法
       for i in range(5):
           time.sleep(random.choice(range(self.interval))) #随机睡眠0-interval秒
           thread_id = threading.get_ident()           #获取当前线程标识符
           print('Thread:{0} Time:{1}\n'.format(thread_id, time.ctime()))
if __name__=='__main__':
    t1 = MyThread(5)     #创建对象
    t2 = MyThread(5)     #创建对象
    t1.start();  t2.start()   #启动线程
