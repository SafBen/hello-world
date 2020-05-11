import numpy as np
import matplotlib.pyplot as plt
a = 5
x = np.array([2,5,7,9])
y = np.array([0, 0, 1-a**3/(7**3), 1-a**3/(9**3)])
plt.plot(x, y)

plt.show() # affiche la figure a l'ecran