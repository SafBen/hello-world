import numpy as np
import matplotlib.pyplot as plt

a = 5.5

def F(x):
    if x >= a:
        return 1-(a/x)**3
    else:
        return 0

x = [i for i in range(-50,50)]
y = [F(i) for i in range(-50,50)]
plt.plot(x, y)

plt.show()