a=1
b=2
def f(a, b):  
    x = 'abc'
    y = 'xyz'  
    for i in range(2):  
        j = i  
        k = i**2
        print(locals())
#测试代码
f(1,2)
print(globals())
