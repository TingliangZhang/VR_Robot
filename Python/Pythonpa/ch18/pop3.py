import getpass, poplib
host = 'YourPop3Host'            #POP3服务器的主机名或IP地址，运行时需修改为对应的值
port = 110                      #POP3服务器的端口号，默认为110，运行时需修改为对应的值
pop3 = poplib.POP3(host, port=port) #创建POP3对象
pop3.user(getpass.getuser())        #用户名
pop3.pass_(getpass.getpass())       #密码
numMessages = len(pop3.list()[1])   #邮件数
for i in range(numMessages):       #接收邮件
    for j in pop3.retr(i+1)[1]:
        print(j)
