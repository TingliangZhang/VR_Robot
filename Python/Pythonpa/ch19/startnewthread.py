import _thread, time, random
def timer(interval):
    for i in range(5):
        time.sleep(random.choice(range(interval))) #随机睡眠0-interval秒
        thread_id = _thread.get_ident()          #获取当前线程标识符
        print('Thread:{0} Time:{1}\n'.format(thread_id, time.ctime()))
def test(): #使用start_new_thread()函数创建2个线程
    _thread.start_new_thread(timer, (5,))  #创建线程
    _thread.start_new_thread(timer, (5,))  #创建线程
if __name__=='__main__':
    test()
