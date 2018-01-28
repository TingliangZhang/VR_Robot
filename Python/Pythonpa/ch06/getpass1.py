import getpass
username = input("用户名:")        #提示输入用户名
passwd = getpass.getpass("密码:")  #提示输入密码
if username == 'jianghong' and passwd == 'password':#实际运用中，需要与数据库中的账户信息比较
    print('登录成功')
else:
    print('登录失败')
