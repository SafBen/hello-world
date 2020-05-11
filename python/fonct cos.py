import numpy as np
import matplotlib.pyplot as plt

f = 10
omega = 2*np.pi*f
t1 = np.linspace(-2*np.pi*100,2*np.pi*100, 50)
t2 = np.linspace(-2*np.pi,2*np.pi, 100)
t3 = np.linspace(-2*np.pi,2*np.pi, 200)
y1 = np.cos(omega*t1)
y2 = np.cos(omega*t2)
y3 = np.cos(omega*t3)

plt.subplot(221)
plt.plot(t1, y1)
plt.subplot(222)
plt.plot(t2, y2)
plt.subplot(223)
plt.plot(t3, y3)

plt.show()