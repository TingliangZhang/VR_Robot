import threading, time, random
class Container1():                      #基于同步和通信
    def __init__(self):                   #构造函数
        self.contents = 0                #容器内容
        self.available = False            #容器内容
        self.cv = threading.Condition()    #条件变量
    def put(self, value):                 #生产函数
        with self.cv:                  #使用条件变量同步
            if self.available:           #如果已经生产，则等待
                self.cv.wait()         #等待
            self.contents = value       #生产，设置内容
            t = threading.current_thread()
            print('{0}生产{1}'.format(t.name, self.contents))
            self.available = True       #设置容器状态：已生产
            self.cv.notify()            #通知等待的消费者
    def get(self):                     #消费函数
        with self.cv:                 #使用条件变量同步
            if not self.available:       #如果已经生产，则等待
                self.cv.wait()        #等待
            t = threading.current_thread()
            print('{0}消费{1}'.format(t.name, self.contents))
            self.available = False      #设置容器状态：未生产
            self.cv.notify()           #通知等待的生产者
class Container2():                    #无同步和通信
    def __init__(self):                #构造函数
        self.contents = 0             #容器内容
        self.available = False         #容器内容
    def put(self, value):              #生产函数
        if self.available:             #如果已经生产
            pass
        else:
            self.contents = value     #生产，设置内容
            t = threading.current_thread()
            print('{0}生产{1}'.format(t.name, self.contents))
            self.available = True      #设置容器状态：已生产
    def get(self):                    #消费函数
        if not self.available:          #如果已经生产，则等待
            pass
        else:
            t = threading.current_thread()
            print('{0}消费{1}'.format(t.name, self.contents))
            self.available = False      #设置容器状态：未生产
class Producer(threading.Thread):        #生产者类
    def __init__(self, container):         #构造函数
        threading.Thread.__init__(self)   #调用父类构造函数
        self.container = container       #容器
    def run(self):                     #定义run方法
        for i in range(1,6):
            time.sleep(random.choice(range(5)))#随机睡眠[0-5)秒
            self.container.put(i)            #生产
class Consumer(threading.Thread):           #消费者类
    def __init__(self, container):             #构造函数
        threading.Thread.__init__(self)      #调用父类构造函数
        self.container = container           #容器
    def run(self):                         #定义run方法
        for i in range(1,6):
            time.sleep(random.choice(range(5)))#随机睡眠[0-5)秒
            self.container.get()              #消费
def test1():
    print('基本同步和通信的生产者消费者模型：')
    container = Container1()        #创建容器
    Producer(container).start()      #创建消费者线程并启动
    Consumer(container).start()     #创建消费者线程并启动
def test2():
    print('无同步和通信的生产者消费者模型：')
    container = Container2()        #创建容器
    Producer (container).start()      #创建消费者线程并启动
    Consumer(container).start()     #创建消费者线程并启动
if __name__=='__main__':
    test2()
