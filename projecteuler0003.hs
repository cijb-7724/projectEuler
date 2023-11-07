main = print (calc (sqrtInt n 0))

n = 600851475143

sqrtInt 0 _ = 0
sqrtInt n r
	| r*r > n = r-1
	| otherwise = sqrtInt n (r+1)

judgePrime a p
	| p > sqrtInt a 0 = True
	| mod a p == 0 = False
	| otherwise = judgePrime a (p+1)

calc x
	| mod n x == 0 && judgePrime x 2 = x
	| otherwise = calc (x-1)

