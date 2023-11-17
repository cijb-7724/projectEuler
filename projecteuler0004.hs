main = print $ solve c 0

c :: [Integer]
c = [x*y|x<-[100..999], y<-[100..999]]

judge n =
	if n > 100000
	then
		let
			na = div n 100000
			nb = mod (div n 10000) 10
			nc = mod (div n 1000) 10
			nd = mod (div n 100) 10
			ne = mod (div n 10) 10
			nf = mod n 10
		in
			if (na == nf && nb == ne && nc == nd)
			then True
			else False
	else
		False

	
solve [] mx = mx
solve (hd:tl) mx
	| judge hd && hd > mx = solve tl hd
	| otherwise = solve tl mx

--the answer is 906609