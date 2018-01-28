import math
import sys
b = float(sys.argv[1])
c = float(sys.argv[2])
discriminant = b*b - 4.0*c
if discriminant>=0:
    d = math.sqrt(discriminant)
    print("x1=",(-b + d) / 2.0)
    print("x2=",(-b - d) / 2.0)
else:
    print("此方程无实数解")    
