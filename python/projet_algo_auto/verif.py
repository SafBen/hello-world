from reader import readResult


def verif():
    t=readResult()
    for i in range(len(t)):
        cl = cm = cn = 0
        for l in t[i]:
            if l=='L':
                cl+=1
            elif l=='M':
                cm+=1
            elif l=='N':
                cn+=1
        print(calculModulo(cl, cm, cn))


def calculModulo(l,m,n):
    nb=l+m+n
    print(l,m,n)
    if nb%3==0:
        if not (l==m and m==n):
            return "faux on devrait avoir l=m=n"
        else:
            return "vrai"
    elif nb%3==1:
        if l==m and m+1==n:
            return "vrai"
        else:
            return "faux on devrait avoir n+1"
    else:
        if l+1==m and m==n:
            return "vrai"
        else:
            return "faux on devrait avoir n+1 et m+1"

def verif_exo3():
    t=readResult()
    for i in range(len(t)):
        t[i]=t[i].strip()
        cl = cm = cn = 0
        for l in t[i]:
            if l=='L':
                cl+=1
            elif l=='M':
                cm+=1
            elif l=='N':
                cn+=1
        print("Taille = "+str(len(t[i])))
        print("Nombre de L = "+str(cl))