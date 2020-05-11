import numpy as np
import matplotlib.pyplot as plt

a1 = -5
a2 = 0
a3 = 5
x = np.linspace(5,30, 30)
y1 = 1 - a1**3/(x**3)
y2 = 1 - a2**3/(x**3)
y3 = 1 - a3**3/(x**3)
#plt.plot(x, y1)
#plt.plot(x, y2)
plt.plot(x, y3)

plt.show() # affiche la figure a l'ecra