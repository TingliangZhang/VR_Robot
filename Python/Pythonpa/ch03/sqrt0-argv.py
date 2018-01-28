import sys
EPSILON = 1e-15
c = float(sys.argv[1])
t = c
while abs(t - c/t) > (EPSILON * t):
    t = (c/t + t) / 2.0 # 将t和c/t的平均值赋值给t
print(t)
