def somme_i_carre(n):
    return n * (n + 1) * (2 * n + 1) // 6


def somme_i(n):
    return n * (n + 1) // 2


print(somme_i(100) ** 2 - somme_i_carre(100))