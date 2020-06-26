f=open("input/probleme13.txt","r")

def read():
    lines = f.readlines()
    sum=0
    for line in lines:
        sum+=int(line)
    return sum

def probleme13():
    c=str(read())
    print(c[0:10])

probleme13()