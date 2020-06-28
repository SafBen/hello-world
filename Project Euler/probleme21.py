def diviseur(n):
    d=[1]
    for i in range(2,int(n**0.5)):
        if n%i==0:
            d.append(i)
            d.append(n//i)
    return d

def somme(d):
    sum=0
    for i in d:
        sum+=i
    return sum

def prob21():
    amicable=[]
    sum1=sum2=0
    for i in range(10000):
        sum1=somme(diviseur(i))
        sum2=somme(diviseur(sum1))
        if sum2==i and sum1!=sum2:
            amicable.append(i)
    return somme(amicable)

print(prob21())