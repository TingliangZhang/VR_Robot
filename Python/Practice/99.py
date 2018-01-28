# 9*9
import math
for i in range(1,10):
    s=""
    for j in range(1,10):
        s+=str.format("{0:1}*{1:1}={2:<2}  ", i , j , i*j )
    print(s)
