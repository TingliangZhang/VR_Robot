import configparser
def ini_create():   #创建INI文件
    config = configparser.ConfigParser()
    config['SystemInfo'] = {'port':'8080'}
    config['GameInfo'] = {'level':1, 'scores':0}
    with open('example.ini', 'w') as configfile:
        config.write(configfile)
def ini_read_write(): #读取和设置INI文件
    config = configparser.ConfigParser()
    config.read('example.ini')
    config['SystemInfo']['port'] = '8088'
    config.set('GameInfo', 'scores', '1000')
    for item in config.items('GameInfo'): print(item)
    with open('example.ini', 'w') as configfile:
        config.write(configfile)
if __name__ == '__main__':
    ini_create()      #创建INI文件
    ini_read_write()  #读取和设置INI文件
