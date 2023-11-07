main =
	print (calc a)


a = [1..1000-1]

calc :: [Int] -> Int
calc [] = 0
calc (hd:tl)
	| mod hd 3 == 0 = hd + calc tl
	| mod hd 5 == 0 = hd + calc tl
	| otherwise = calc tl

