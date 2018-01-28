class TemperatureConverter:
    @staticmethod 
    def c2f(t_c): #摄氏温度到华氏温度的转换
            t_c = float(t_c)
            t_f = (t_c * 9/5) + 32
            return t_f
    @staticmethod 
    def f2c(t_f): #华氏温度到摄氏温度的转换
            t_f = float(t_f)
            t_c = (t_f - 32) * 5 /9
            return t_c
#测试代码
print("1. 从摄氏温度到华氏温度.")
print("2. 从华氏温度到摄氏温度.")
choice = int(input("请选择转换方向："))
if choice == 1:
    t_c = float(input("请输入摄氏温度： "))
    t_f = TemperatureConverter.c2f(t_c)
    print("华氏温度为： {0:.2f}".format(t_f))
elif choice == 2:
    t_f = float(input("请输入华氏温度： "))
    t_c = TemperatureConverter.f2c(t_f)
    print("摄氏温度为： {0:.2f}".format(t_c))
else:
    print("无此选项，只能选择1或2！")
