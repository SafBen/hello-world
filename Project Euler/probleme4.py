def is_palindrome(n):
    decompo = []
    while n > 9:
        decompo.append(n % 10)
        n //= 10
    decompo.append(n)
    for i in range(len(decompo) // 2):
        if decompo[i] != decompo[len(decompo) - i - 1]:
            return False
    return True


def n_digit(n):
    max = a = b = 0
    for i in range(10 ** n - 1, 10 ** (n - 1), -1):
        for j in range(10 ** n - 1, 10 ** (n - 1), -1):
            if i * j > max and is_palindrome(i * j):
                max = i * j
                a = i
                b = j
    return max, a, b