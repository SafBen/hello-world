def is_divisible(n, x):
    for i in range(x, 10, -1):
        if n % i != 0:
            return False
    return True


def smallest():
    i = 1
    while not is_divisible(i, 20):
        i += 1
    return i