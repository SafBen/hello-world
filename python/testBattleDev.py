import sys

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))
	
nombre=lines[1].split()

compteur=0

for i in range(int(lines[0])):
	if int(nombre[i])<=9 and int(nombre[i]) >=5:
		compteur+=1

print(compteur)
	