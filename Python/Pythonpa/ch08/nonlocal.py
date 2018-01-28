def outer_func():
    tax_rate = 0.17  #上级函数体中的局部变量
    print('outer fucnc tax rate =', tax_rate) #输出上级函数体中局部变量的值
    def innner_func():
        nonlocal tax_rate #不是所在块的局部变量，而是在上级函数体中定义的局部变量
        tax_rate = 0.05  #上级函数体中的局部变量重新赋值
        print('inner func tax rate =', tax_rate) #输出上级函数体中局部变量的值
    innner_func()                       #调用函数
    print('outer fucnc tax rate =', tax_rate)   #输出上级函数体中局部变量的值（已更改）
#测试代码
outer_func()

