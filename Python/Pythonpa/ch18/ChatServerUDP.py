#ChatServerUDP.py
import socket #导入socket模块
serversocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) #创建服务器socket
serversocket.bind(('127.0.0.1', 8000)) #绑定到IP地址和端口号
while 1: #循环以接收和回送客户机数据
    data, address = serversocket.recvfrom(1024) #接收数据，返回数据和客户机地址
    if not data: break; #接收到空数据时，终止循环
    print('Received from client: ', address, repr(data)) #输出接收到的数据，repr函数转换为字符串
    print('Echo: ', repr(data)) #输出发送到客户机数据的信息
    serversocket.sendto(data, address) #发送数据到客户机
serversocket.close() #关闭服务器socket
