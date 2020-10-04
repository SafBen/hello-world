# Source : openclassroom

import random
import sys
from threading import Thread
import time

class Afficheur(Thread):

    """Thread chargé simplement d'afficher un mot dans la console."""

    def __init__(self, nombre):
        Thread.__init__(self)
        self.nombre = nombre

    def run(self):
        """Code à exécuter pendant l'exécution du thread."""
        n=self.nombre
        a=time.time()
        x=0
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    x+=1
        print("x = ",x,"temps d'une thread = ",time.time()-a)

tps=time.time()
# Création des threads
thread_1 = Afficheur(350)
thread_2 = Afficheur(350)

# Lancement des threads
thread_1.start()
thread_2.start()

# Attend que les threads se terminent
thread_1.join()
thread_2.join()
print("temps global = ",time.time()-tps)