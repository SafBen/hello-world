from reader import read
import matplotlib.pyplot as plt
import numpy as np
import math

def plot(exo,n_iteration,pas,nb=""): # exo = numero de l'exercice
    x,y=[],read(nb)
    for i in range(len(y)):
        x.append(pas*i)
    plt.plot(x,y,"-p",label="donnée")
    x = np.linspace(1, (n_iteration-1)*pas, 5*pas*n_iteration)
    if exo==1 or exo==2:
        y = x**2/2.2+10
    elif exo==3:
        y=x*np.log2(x)
    elif exo==4:
        y = 3*(x+1)
    plt.plot(x, y,"-g",label="fonction")
    y=7*x*np.log2(x)
    plt.plot(x, y, "-*", label="fonction 7*x*np.log2(x)")
    plt.legend(loc="upper left")
    plt.show()


def f(n):
    X=[]
    for i in range(1, n):
        x = i
        c = 0
        while x >= 3:
            x = 2 * x // 3
            c += 1
        X.append(c)
    return X

#print(f(100))
#print(math.ceil(math.log(i,2/3)))

def plot2():
    x = np.linspace(1, 10000, 10000)
    y=np.log2(x)*x
    plt.plot(x,y, "-*", label="fonction x*log2(x)")
    y = np.log10(x) * x
    plt.plot(x, y, "-g", label="fonction x*log10(x)")
    y = x * np.log(x) / np.log(1.5)
    plt.plot(x, y, "-r", label="log3")
    y=f(10001)
    plt.plot(x,x*y,"-h", label="fonction f")
    plt.legend(loc="upper left")
    plt.show()

#plot2()



