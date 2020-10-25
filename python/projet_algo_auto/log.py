import math

def g(n,mod):
    x=n*"X"
    y=''
    for j in range(int(math.log(n,3))+1):
        print(x)
        cx=mod
        for i in range(n):
            if x[i]=='X':
                cx+=1
            if cx%3!=0 or cx==0:
                y+=' '
            else:
                y+='X'
                cx=0
        x=y
        y=''

g(99,0)

def test():
    for i in range(3,10):
        g(i,0)
        print('\n')

#test()

print(math.log(99,1.5))