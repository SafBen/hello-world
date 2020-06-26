def is_prime(n):
    if n % 2 == 0:
        return False
    for i in range(3, int(n ** 0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def prob10(n):
    sum = 2
    for i in range(3, n):
        if is_prime(i):
            sum += i
    return sum


print(prob10(2000000))