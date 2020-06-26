t=[1,2]
sum=2
def create_fibo():
    global sum
    i=len(t)
    while t[i-1]<4000000:
        t.append(t[i-1]+t[i-2])
        if t[i]%2==0:
            sum+=t[i]
        i+=1
    print(sum)
create_fibo()