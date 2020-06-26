fact = []
N = 600851475143


def factor(n):
    for i in range(1, int(n ** 0.5)):
        if n % i == 0:
            fact.append(i)
            fact.append(n // i)


def is_prime(n):
    for i in range(3, int(n ** 0.5), 2):
        if n % i == 0:
            return False
    return True


def result3():
    for i in range(len(fact) - 1, 1, -1):
        if is_prime(fact[i]):
            return fact[i]


factor(N)
print(result3())