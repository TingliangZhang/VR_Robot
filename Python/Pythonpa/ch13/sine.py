import matplotlib.pyplot as plt
import math
x = [2*math.pi*i/100 for i in range(100)]
y = [math.sin(i) for i in x] 
plt.plot(x, y)
plt.show()
