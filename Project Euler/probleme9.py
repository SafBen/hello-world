def prob9():
    for i in range(333,1000):
        for j in range(i):
            for k in range(j):
                if i+j+k==1000:
                    if i*i==j*j+k*k:
                        return i,j,k,i*j*k

print(prob9())
