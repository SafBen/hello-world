f=open("input/probleme11.txt")

def read():
    t=[]
    lines=f.readlines()
    for line in lines:
        t.append(line)
        t[-1]=t[-1].split()
    for i in range(len(t)):
        for j in range(len(t[0])):
            t[i][j]=int(t[i][j])
    return t

def max_mult_line(n,t):
    mult=1
    max=l=c=0
    for i in range(len(t)):
        for j in range(len(t[0])-n):
            for k in range(n):
                mult=mult*t[i][j+k]
                if max<mult:
                    max=mult
                    l=i
                    c=j
            mult=1
    print(max,l,c)
    return max

def max_mult_col(n,t):
    mult=1
    max=l=c=0
    for i in range(len(t[0])):
        for j in range(len(t)-n):
            for k in range(n):
                mult=mult*t[j+k][i]
                if max<mult:
                    max=mult
                    l=i
                    c=j
            mult=1
    print(max,l,c)
    return max

def max_mult_diag_droite(n,t):
    mult=1
    max=l=c=0
    for i in range(len(t)-n):
        for j in range(len(t[0])-n):
            for k in range(n):
                mult=mult*t[i+k][j+k]
                if max<mult:
                    max=mult
                    l=i
                    c=j
            mult=1
    print(max,l,c,t[l][c])
    return max

def max_mult_diag_gauche(n,t):
    mult=1
    max=l=c=0
    for i in range(len(t)-1,n,-1):
        for j in range(len(t[0])-1,n,-1):
            for k in range(n):
                mult=mult*t[i-k][j-k]
                if max<mult:
                    max=mult
                    l=i
                    c=j
            mult=1
    print(max,l,c,t[l][c])
    return max

t=read()
print(max(max_mult_line(4,t),max_mult_col(4,t),max_mult_diag_droite(4,t),max_mult_diag_gauche(4,t)))