f=open("input/probleme18.txt","r")

def read():
    t=[]
    lines=f.readlines()
    for line in lines:
        t.append(line)
        t[-1]=t[-1].split()
    for i in range(len(t)):
        for j in range(len(t[i])):
            t[i][j]=int(t[i][j])
    return t

def test_all():
    t=read()
    indice=max=0
    for i in range(len(t)-1):
        t[i + 1][0] += t[i][0]
        t[i + 1][-1] += t[i][-1]
        for j in range(1,len(t[i])-1):
            t[i][j]+=Max(t[i-1][j-1],t[i-1][j])
    for j in range(1, len(t[14]) - 1):
        t[14][j] += Max(t[14 - 1][j - 1], t[14 - 1][j])
    for k in range(len(t[-1])):
        if t[-1][k]>max:
            max=t[-1][k]
            indice=k
    return max,indice

def Max(a,b):
    if a>=b:
        return a
    else:
        return b
print(test_all())