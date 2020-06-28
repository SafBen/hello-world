def fact(n):
    if n==0:
        return 1
    else:
        return n*fact(n-1)

c=str(fact(100))

sum=0
for i in c:
    sum+=int(i)

print(sum)