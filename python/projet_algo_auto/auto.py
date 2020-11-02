"""Create by Safwane 5/10/2020
   https://matplotlib.org/3.3.2/api/_as_gen/matplotlib.pyplot.plot.html for plot format"""


import os
import time

from plot import plot

from reader import copy
from verif import verif, verif_exo3

pas=5
n_iteration=10

def run(exo): # n= itération    exo = numero de l'exercice
    f=open("Size/size.txt", "w")
    f.close()
    f = open("Result/result.txt", "w")
    f.close()
    if exo==2 or exo==3:
        x = 'python3 -m am simulate EXO/EXO'+str(exo)+'.txt -t "<X>" -r'
        X = "<X>"
    else:
        x = 'python3 -m am simulate EXO/EXO' + str(exo) + '.txt -t "XX" -r'
        X = "XX"
    for i in range(n_iteration):
        start=time.time()
        os.system(x)
        end=time.time()
        #print(end-start)
        Y=X
        if exo==2 or exo==3:
            X = X.replace("<X>", "X")
            X += (pas - 1) * "X"
            X += "<X>"
        else:
            X+=pas*"X"
        y = x
        x = y.replace(Y, X)

def run5():
    f = open("Size/size.txt", "w")
    f.close()
    f = open("Result/result.txt", "w")
    f.close()
    x = 'python3 -m am simulate EXO/EXO5.txt -t "11"'
    X="11"
    for i in range(n_iteration):
        os.system(x)
        Y=X
        X += pas * "1"
        y = x
        x = y.replace(Y, X)


#run5()
run(2)
#verif_exo3()
verif()
#copy(3,True)
plot(3,n_iteration,pas,"")

"""
fichier=open("exec.txt", "w")
for j in range(1,5):
    for i in [9, 10, 11, 999, 1000, 1001, 9999, 10000, 10001]:
        if j==3 or j==2:
            fichier.write("python -m am simulate drapeau.txt -n EXO" + str(j) + " -t \"" + (i-1) * "X" +"<X>"+ "\"\n")
        else:
            fichier.write("python -m am simulate drapeau.txt -n EXO"+str(j)+" -t \""+i*"X"+"\"\n")
"""