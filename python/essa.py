import numpy as np
import matplotlib.pyplot as plt


def tout(n, p):  # y,x
    # theta = np.linspace(0, 2*np.pi, 200)
    # x = np.cos(theta)
    # y = np.sin(theta)
    # plt.plot(x, y)
    plt.axis("equal")
    A = []
    l = []
    for i in range(1, p):
        l.append((i, (i * n) % p))
    for i in range(len(l)):
        A.append(l[i][0])
        A.append(l[i][1])
    X = [np.cos(2 * np.pi * i / p) for i in range(p)]
    Y = [np.sin(2 * np.pi * i / p) for i in range(p)]
    for i in range(0, len(A), 2):
        plt.plot([X[A[i]], X[A[i + 1]]], [Y[A[i]], Y[A[i + 1]]], color='blue', linewidth=0.5)
    plt.show()

tout(2,100)