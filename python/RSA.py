import time

def decode(n):
    a = time.time()
    p = 2
    q = n-p
    for i in range(n-1):
        for j in range(n-1):
            if p*q == n:
                b = time.time()
                c = b-a
                return (p,q,c)
            else:
                q-=1
        p += 1
        q = n-p
        return 0,0,0

a,b,c=decode(19)
print(a,b,c)