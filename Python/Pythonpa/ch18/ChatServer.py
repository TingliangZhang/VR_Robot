import socket                   #导入socket模块
serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #创建服务器socket
serversocket.bind(('127.0.0.1', 8000)) #绑定到IP地址和端口号
serversocket.listen(1)             #开始侦听，队列长度为1
clientsocket, clientaddress = serversocket.accept() #使用阻塞方法accept以等待客户机连接请求
print('Connection from ', clientaddress)    #接收客户机请求后输出客户机的信息
while 1:                             #循环以接收和回送客户机数据
    data = clientsocket.recv(1024)        #接收数据
    if not data: break                   #接收到空数据时，终止循环
    print('Received from client: ', repr(data)) #输出接收到的数据，repr函数转换为字符串
    print('Echo: ', repr(data))             #输出发送到客户机数据的信息
    clientsocket.send(data)              #回送数据到客户机
clientsocket.close()                     #关闭客户机socket
serversocket.close()                     #关闭服务器socket
