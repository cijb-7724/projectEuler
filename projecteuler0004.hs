main = print (length c)

a = [100..999]
b = [100..999]
c = [x*y|x<-a, y<-b]

judge num
	if n > 100000
	then
		na = div n 100000
		nb = mod (div n 10000) 10
		nc = mod (div n 1000) 10
		nd = mod (div n 100) 10
		ne = mod (div n 10) 10
		nf = mod n 10
		if (na == nf && nb == ne && nc == nd)
		then = True
		else = False
	else
		= False