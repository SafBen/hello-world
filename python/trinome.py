def recherche(a,b,c,x):
    for i in range(15):
        x = (a*x**2+c)/(-b)
    return x
    
def trinome(a,b,c):
    d = b**2-4*a*c
    x1,x2 = (-b-d**0.5)/(2*a), (-b+d**0.5)/(2*a)
    return x1,x2