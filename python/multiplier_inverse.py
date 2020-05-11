def nombreEstUnPalindrome(n,m):
	s=str(n)
	sInv=str(m*n)
	if s[0]==sInv[3] and s[1]==sInv[2] and s[2]==sInv[1] and s[3]==sInv[0]:
		return True
	else:
		return False

l=[]
for i in range(2,10):
	for x in range(1000,10000//i):
		if nombreEstUnPalindrome(x,i):
			l.append([x,i])
print(l)