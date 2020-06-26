count=1

def temps_de_vol(n):
    global count
    if n==1:
        return count
    elif n%2==0:
        n//=2
        count+=1
        temps_de_vol(n)
    else:
        n=3*n+1
        count+=1
        temps_de_vol(n)
    return count

def probleme14(n):
    max=result=1
    global count
    for i in range(1,n):
        tps=temps_de_vol(i)
        count=1
        if max<tps:
            max=tps
            result=i
    return max,result

print(probleme14(1000000))