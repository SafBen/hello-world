import numpy as np
import matplotlib.pyplot as plt

theta = np.linspace(0, 2*np.pi, 200)

x = np.cos(theta)
y = np.sin(theta)
plt.plot(x, y)
plt.axis("equal")

plt.show()

##

from math import pi,cos,sin

def multiple(n,p):
    l = []
    for i in range(1,p):
        l.append((i,(i*n)%p))
    return l
    
def recup(n,p):
    A = []
    l = multiple(n,p)
    for i in range(len(l)):
        A.append(l[i][0])
        A.append(l[i][1])
    return A
        
        
    
#x = [0,1,0,-1]     166-350
#y = [1,0,-1,0]
#plt.scatter(x,y)
#plt.show()

def racine_unité(n):
    X = [cos(2*pi*i/n) for i in range(n)]
    Y = [sin(2*pi*i/n) for i in range(n)]
    return X,Y
    
X,Y = racine_unité(12)
plt.scatter(X,Y)

def rel(n,p):
    A = recup(n,p)
    for i in range(0,len(A),2):
        plt.plot([X[A[i]],X[A[i+1]]],[Y[A[i]],Y[A[i+1]]])
    
    
##

def relier(n,p):
    A = recup(n,p)
    for i in range(p):
        plt.plot([A[0],A[2*i%10]],[B[0],B[2*i%10]])
        
##

x = [1,5,3]
y = [2,9,4]

plt.plot(x,y)
plt.show()