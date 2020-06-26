f = open("input/probleme8.txt", "r")

c = f.readline()
n = int(c)


def mult(tab):
    prod = 1
    for i in range(len(tab)):
        prod *= int(tab[i])
    return prod


def prob8():
    p = max = 1
    i = 13
    while i != len(c):
        p = mult(c[i - 13:i])
        i += 1
        if max < p:
            max = p
    return max


print(prob8())