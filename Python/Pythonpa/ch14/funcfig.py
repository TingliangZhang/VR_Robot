import numpy as np
import matplotlib.pyplot as plt
import math
x = np.linspace(0, 2*np.pi, 100)
y1 = np.sin(x)
y2 = np.cos(x)
plt.plot(x, y1, x, y2)
plt.show()
