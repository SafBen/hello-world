def poker():
    Jeu1 = nouveauJeu(1)
    Jeu2 = nouveauJeu(2)
    gagnant = comparer(Jeu1, Jeu2)
    afficher(gagnant)


def afficher(gagnant):
    if gagnant == 0:
        print("Il y a égalité")
    else:
        print("Le gagnant est le joueur", gagnant)


def nouveauJeu(joueur):
    print("Main du joueur", joueur)
    saisie = input()
    while not (controleJeu(saisie)):
        print("Main du joueur ", joueur)
        saisie = input()
    return triJeu(saisie.split())


def controleJeu(saisie):
    return True


def triJeu(liste):
    for i in range(len(liste)):
        for j in range(len(liste) - 1):
            if getValeur(liste[j]) > getValeur(liste[j + 1]):
                liste[j], liste[j + 1] = liste[j + 1], liste[j]
    return liste


def getValeur(carte):
    if len(carte) == 3:
        if carte[0:1] == "V":
            return 11
        elif carte[0:1] == "D":
            return 12
        elif carte[0:1] == "R":
            return 13
        elif carte[0:1] == "A":
            return 14
        else:
            return int(carte[0:1])
    elif len(carte) == 4:
        return 10
    else:
        return int(carte[0:1])


def decompose(liste):
    valeur = []
    couleur = []
    for i in range(len(liste)):
        valeur.append(getValeur(liste[i]))
        couleur.append(liste[i][-2:])
    return valeur, couleur


def comparer(Jeu1, Jeu2):
    point1 = point(Jeu1)
    point2 = point(Jeu2)
    if point1 == point2:
        return 0
    elif point1 > point2:
        return 1
    else:
        return 2


def point(Jeu):
    # carte haute, pair = carte haute + 13, 2 pairs = carte haute + 13 + 2e carte + 13,
    # brelan = carte haute + 60, suite = carte haute + 80, couleur = 100
    # full = 2*(brelan + pair), carre = carte haute + 200, quinteflush = 3*(suite + couleur)
    # quinteroyale = 1000
    valeur, couleur = decompose(Jeu)
    boolCarre, valCarre = carre(valeur)
    boolFull, valBrelanFull, valPairFull = full(valeur)
    boolBrelan, valBrelan = brelan(valeur)
    bool2Pairs, liste2Pairs = deuxPairs(valeur)
    boolPair, valPair = pair(valeur)
    if quinteRoyale(valeur, couleur):
        return 1000
    elif quinteFlush(valeur, couleur):
        return 3 * (80 + valeur[-1] + 100)
    elif boolCarre:
        return 200 + valCarre
    elif boolFull:
        return 2 * (valBrelanFull + valPairFull + 13 + 60)
    elif color(couleur):
        return 100
    elif suite(valeur):
        return 80 + valeur[-1]
    elif boolBrelan:
        return 60 + valBrelan
    elif bool2Pairs:
        return 13 + liste2Pairs[0] + 13 + liste2Pairs[1]
    elif boolPair:
        return 13 + valPair
    else:
        return valeur[-1]


def occurence(valeur, nombre):
    occ = 0
    for i in valeur:
        if (i == nombre):
            occ += 1
    return occ


def pair(valeur):
    p = 0  # nb de pairs
    for i in valeur:
        if occurence(valeur, i) == 2:
            return True, i
    return False, 0


def deuxPairs(valeur):
    p = 0  # nb de pairs
    l = []
    for i in valeur:
        if occurence(valeur, i) == 2:
            l.append(i)
            p += 1  # on compte 2 fois chaque pairs
    l = list(set(l))
    if p == 4:  # donc 2 pairs donne p = 4
        return True, l
    return False, [0, 0]


def brelan(valeur):
    for i in valeur:
        if occurence(valeur, i) == 3:
            # un seul brelan possible
            return True, i
    return False, 0


def suite(valeur):  # liste de nombre triée
    for i in range(len(valeur) - 1):
        if valeur[i] != valeur[i + 1] - 1:
            return False
    return True


def color(couleur):
    for i in range(len(couleur) - 1):
        if couleur[i] != couleur[i + 1]:
            return False
    return True


def full(valeur):
    boolPair, i = pair(valeur)
    boolBrelan, j = brelan(valeur)
    if boolPair and boolBrelan:
        return True, i, j
    return False, 0, 0


def carre(valeur):
    for i in valeur:
        if occurence(valeur, i) == 4:
            # un seul carre possible
            return True, i
    return False, 0


def quinteFlush(valeur, couleur):
    if suite(valeur) and color(couleur):
        return True
    return False


def quinteRoyale(valeur, couleur):
    if suite(valeur) and color(couleur) and valeur[-1] == 14:
        return True
    return False


poker()