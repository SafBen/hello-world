import numpy as np
import matplotlib.pyplot as plt
import cv2

img = cv2.imread('lena.png',0)  

(lignes, colonnes) = img.shape 

#Affichage de l'image originale
"""
plt.figure(1,figsize=(8,8))
plt.imshow(img, cmap='gray'), plt.xticks([]), plt.yticks([])
plt.title('Image Originale')
plt.show() 
"""

#Définition du filtre modélisant le flou de bougé
def filtre_flou(l, c, v, t, theta): # l:ligne ; c:colonne ; v:vitesse ; t:temps ; phi:angle
    L = v*t
    X=np.linspace(-l/2,l/2+1,l)/l
    Y=np.linspace(-c/2,c/2+1,c)/c
    [XX,YY]=np.meshgrid(X,Y)
    H = np.sinc(L*np.pi*((XX*np.cos(theta))+(YY*np.sin(theta))))
    return H



fft = np.fft.fft2(img)
fftshift = np.fft.fftshift(fft)

H1 = filtre_flou(lignes, colonnes, 10, 0.5, np.pi)
filtrage1 = H1*fftshift #Filtrage de l'image : multiplication du filtre par la fftshift de l'image en frequentiel

#Reconstruction de l'image avec flou de bougé dans le domaine spatiale avec la transformée inverse
imagefloutee1 = np.fft.ifft2(filtrage1)
imagefloutee1 = np.abs(imagefloutee1)



H2 = filtre_flou(lignes, colonnes, 30, 0.5, np.pi)
filtrage2 = H2*fftshift #Filtrage de l'image : multiplication du filtre par la fftshift de l'image en frequentiel

#Reconstruction de l'image avec flou de bougé dans le domaine spatiale avec la transformée inverse
imagefloutee2 = np.fft.ifft2(filtrage2) 
imagefloutee2 = np.abs(imagefloutee2)



H3 = filtre_flou(lignes, colonnes, 15, 0.5, np.pi/4)
filtrage3 = H3*fftshift #Filtrage de l'image : multiplication du filtre par la fftshift de l'image en frequentiel

#Reconstruction de l'image avec flou de bougé dans le domaine spatiale avec la transformée inverse
imagefloutee3 = np.fft.ifft2(filtrage3) 
imagefloutee3 = np.abs(imagefloutee3)



H4 = filtre_flou(lignes, colonnes, 15, 2, np.pi)
filtrage4 = H4*fftshift #Filtrage de l'image : multiplication du filtre par la fftshift de l'image en frequentiel

#Reconstruction de l'image avec flou de bougé dans le domaine spatiale avec la transformée inverse
imagefloutee4 = np.fft.ifft2(filtrage4) 
imagefloutee4 = np.abs(imagefloutee4)




#affichage des images avec flou de bougé
plt.figure(2,figsize = (15,15)) 

plt.subplot(221)
plt.imshow(imagefloutee1, cmap = 'gray')
plt.title('image floutee : v = 10 ; t = 0.5 ; theta = pi')
plt.xticks([]), plt.yticks([])


plt.subplot(222)
plt.imshow(imagefloutee2, cmap='gray'), plt.xticks([]), plt.yticks([])
plt.title('image floutee : v = 30 ; t = 0.5 ; theta = pi')

plt.subplot(223)
plt.imshow(imagefloutee3, cmap='gray'), plt.xticks([]), plt.yticks([])
plt.title('image floutee : v = 15 ; t = 0.5 ; theta = pi/4')

plt.subplot(224)
plt.imshow(imagefloutee4, cmap='gray'), plt.xticks([]), plt.yticks([])
plt.title('image floutee : v = 15 ; t = 2 ; theta = pi')

plt.show()