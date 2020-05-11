import time
import numpy as np
import matplotlib.pyplot as plt

##

def est_premier(n):
    if n<=1:
        return False
    bool = True
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            bool = False
    return bool
    
    
def est_premier_rapide(n):
    if n<=1:
        return False
    elif n==2:
        return True
    elif n%2:
        return False
    for i in range(3,int(n**0.5)+1,2):
        if n%i==0:
            return False
    return True
    
    
def liste_premier(n):
    liste=[]
    for i in range(n):
        if est_premier(i):
            liste.append(i)
    return liste
    
def liste_premier_rapide(n):
    liste=[]
    for i in range(n):
        if est_premier_rapide(i):
            liste.append(i)
    return liste
    
    
##
nb = 1000000

a=time.time()
#l1=liste_premier(nb)
b=time.time()
print(b-a,"\n")

a=time.time()
l2=liste_premier_rapide(nb)
b=time.time()
print(b-a)





##

print(l,len(l))
X=[]
temps=[]
longueur=[]

##




for i in range(10,100000,10000):
    X.append(i)
    a=time.time()
    l_prem=liste_premier_rapide(i)
    b=time.time()
    longueur.append(len(l_prem))
    temps.append(b-a)



##

plt.plot(X, temps)
plt.plot([X[0],X[-1]],[temps[0],temps[-1]])

plt.show()

##

plt.plot(X, longueur)

plt.show()
