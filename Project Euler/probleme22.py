f=open("input/probleme22.txt")
letter_count = dict([(chr(i).upper(),i-96) for i in range(97,123)])

def read():
    t=f.readlines()
    names=[]
    for name in t[0].split(","):
        names.append(name)
    names.sort()
    return names


def somme(c):
    s=0
    for i in c:
        if i!="\"":
            s+=letter_count[i]
    return s

def score():
    names = read()
    sum=tot=0
    for i in range(len(names)):
        sum=somme(names[i])
        sum*=(i+1)
        tot+=sum
    return tot

print(score())