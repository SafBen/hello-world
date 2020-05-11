def X(x):
    a = 28
    if x >= -3 and x <= 3:
        return x**2/a
    else:
        return 0
    
def E(X):
    return sum(x*X(x) for x in range(-3,4))
    
def E2(X):
    return sum(x**2*X(x) for x in range(-5,5))
    
##

def partition(n,p):
    a = []
    b = []
    for i in range(p):
        a.append(1)
    for i in range(p-1,0,-1):
        while a[i] < n-p:
            if sum(j for j in a) == n:
                b.append(a)
            a[i] +=1
    return a,b
    
def test():
    for i in range(10,0,-1):
        print(i)
        
def partition2(n,p):
    a = []
    b = 0
    for i in range(p):
        a.append(1)
    for i in range(p):
        for j in range(n-p+1):
            if sum(e for e in a) == n:
                b+=1
                #return a,b
                a[i] +=1
                print(a)
            else:
                a[i] +=1
                print(a)
        a[i] = 1
    return a,b
    
def partition3(n,p):
    a = []
    b = 0
    for i in range(p):
        a.append(1)
    for k in range(n-1):
        for j in range(n-1):
            for i in range(n-1):
                if sum(e for e in a) == n:
                    b+=1
                    a[2] +=1
                    print(a)
                else:
                    a[2] +=1
                    print(a)
            a[1] += 1
            a[2] = 1
        a[0] += 1
        a[1] = 1
        a[2] = 1
    return a,b
    
##

# Dénombrement

def fact(n):
    if n == 0:
        return 1
    else:
        return n*fact(n-1)

def coefbin(n,p):
    return fact(n)/(fact(p)*fact(n-p))




































