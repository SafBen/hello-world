def sum(n):
    s=0
    for i in range(n+1):
        s+=i
    return s

def diviseur(n):
    div=[]
    for i in range(1,int(n**0.5)):
        if n%i==0:
            div.append(i)
            div.append(n//i)
    return div

def prob12(n):
    i=1
    while len(diviseur(sum(i)))<n:
        i+=1
    return sum(i)

print(prob12(500))