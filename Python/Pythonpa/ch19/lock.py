import threading, time, random
class Account(threading.Thread):              #继承threading.Thread
    lock = threading.Lock()                  #创建锁
    def __init__(self, amount):                #构造函数
        threading.Thread.__init__(self)         #调用父类构造函数
        Account.amount = amount            #账户金额
    def run(self):                           #定义run方法
        self.withdraw()                     #取款
    def withdraw(self):
        #Account.lock.acquire()   #获取锁。注释不使用同步处理
        t = threading.current_thread()
        a = random.choice(range(50,101))
        if Account.amount < a:
            print('{0}交易失败。取款前余额：{1}，取款额：{2}'.format(t.name, Account.amount, a))
            Account.lock.release()
            return 0                          #拒绝交易
        time.sleep(random.choice(range(5)))       #随机睡眠[0-5)秒
        prev = Account.amount
        Account.amount -= a                   #取款
        print('{0}取款前余额：{1}, 取款额：{2}, 取款后额：{3}'.format(t.name, prev, a, Account.amount))
        #Account.lock.release()  #释放锁。注释不使用同步处理
def test():
    for i in range(5):                  #创建10个线程对象并启动
        Account(200).start()
if __name__=='__main__':
    test()
