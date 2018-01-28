pi = 3.141592653589793 #全局变量
e = 2.718281828459045 #全局变量
def my_func():
    global pi #全局变量，与前面的全局变量pi指向相同的对象
    pi = 3.14 #改变了全局变量的值
    print('global pi =', pi) #输出全局变量的值
    e = 2.718 #局部变量，与前面的全局变量e指向不同的对象
    print('local e =', e)  #输出局部变量的值
print('module pi =', pi)   #输出全局变量的值
print('module e =', e)   #输出全局变量的值
my_func()           #调用函数
print('module pi =', pi)  #输出全局变量的值，该值在函数中已被更改
print('module e =', e)   #输出全局变量的值
