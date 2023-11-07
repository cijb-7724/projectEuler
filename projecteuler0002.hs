main = print (evenSum(calc a))
a = [2,1]

calc (hd:tl)
	| hd > 4000000 = tl
	| otherwise = calc ([hd+head tl]++[hd]++tl)

evenSum [] = 0
evenSum (hd:tl)
	| mod hd 2 == 0 = hd + evenSum tl
	| otherwise = evenSum tl
