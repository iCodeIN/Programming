def mdc(a,b):
	if b == 0: return a
	else: return mdc(b, a % b)

l, r = map(long,raw_input().split())
terminou = False
i = j = k = l
while i < r+1:
	j = i+1
	while j < r+1:
		k = j+1
		while k < r+1:
			if(mdc(i,j) == 1 and mdc(j,k) == 1 and mdc(i,k) != 1):
				terminou  = True
				break
			k += 1
		if terminou: break
		j += 1

	if terminou: break	
	i += 1
if terminou:
	print i,j,k
else:
	print -1
