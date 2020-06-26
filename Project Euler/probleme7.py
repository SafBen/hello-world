prime = [2, 3]


def prob7(n):
    i = 5
    while len(prime) < n:
        if is_prime(i):
            prime.append(i)
        i += 2
    return prime[-1]


def is_prime(n):
    for i in range(3, int(n ** 0.5) + 1, 2):
        if n % i == 0:
            return False
    return True