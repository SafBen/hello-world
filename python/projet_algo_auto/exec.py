
import os

def exec():
    f = open("exec3.txt", "r")
    lines = f.readlines()
    for line in lines:
        os.system(line)
#exec()


def create_exec():
    fichier = open("exec3.txt", "w")
    for j in range(1, 5):
        for i in [9, 10, 11, 999, 1000, 1001, 9999, 10000, 10001]:
            if j == 3 or j == 2:
                fichier.write(
                    "python -m am simulate drapeau.txt -n EXO" + str(j) + " -t \"" + (i - 1) * "X" + "<X>" + "\" -r\n")
            else:
                fichier.write("python -m am simulate drapeau.txt -n EXO" + str(j) + " -t \"" + i * "X" + "\" -r\n")


def create_exec3():
    fichier = open("exec3.txt", "w")
    for j in range(1, 5):
        for i in [9, 10, 11, 999, 1000, 1001, 9999, 10000, 10001]:
            if j == 3 or j == 2:
                fichier.write(
                    "python3 -m am simulate drapeau.txt -n EXO" + str(j) + " -t \"" + (i - 1) * "X" + "<X>" + "\" -r\n")
            else:
                fichier.write("python3 -m am simulate drapeau.txt -n EXO" + str(j) + " -t \"" + i * "X" + "\" -r\n")

create_exec3()

import os
import time

import multiprocessing as mp



def exec(a,b):
    f = open("exec3.txt", "r")
    lines = f.readlines()
    for i in range(a,b):
        print("Simulation : ", i)
        start = time.time()
        os.system(lines[i])
        end = time.time()
        print("time = ", end - start,"\n")

def process():
    p = []
    tab = [[9, 15], [15, 16], [16, 17], [17, 18], [18, 24], [24, 25], [25, 27], [27, 36]]

    for t in tab:
        p.append(mp.Process(target=exec, args=(t[0], t[1])))

    for i in range(len(p)):
        p[i].start()
    for i in range(len(p)):
        p[i].join()

process()