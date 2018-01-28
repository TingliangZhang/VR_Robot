import math
import sys
n = int(sys.argv[1])
for i in range(n+1):
    x = math.pi * i / n
    y = math.sin(x) + math.sin(5 * x)
    print(x, y)
