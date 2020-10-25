# copy fichier size.txt dans un fichier size_i.txt
def copy(i,isSize):
    if isSize:
        f=open("Size/size"+str(i)+".txt","w")
        g=open("Size/size.txt", "r")
    else:
        f = open("Result/result" + str(i) + ".txt", "w")
        g = open("Result/result.txt", "r")
    f.write(g.read())


def read(exo=""): # exo = numero de l'exercice
    f = open("Size/size"+str(exo)+".txt")
    t = []
    lines = f.readlines()
    for line in lines:
        t.append(int(line))
    return t


def readResult(exo=""): # exo = numero de l'exercice
    f = open("Result/result"+str(exo)+".txt")
    t = []
    lines = f.readlines()
    for line in lines:
        t.append(line)
    return t