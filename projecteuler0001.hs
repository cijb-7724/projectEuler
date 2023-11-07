main = 
	print b

--a = take 5 (map (\x -> show (10*x)) [1..])
--b = take 6 (map (\x -> show(x) ++ "0") [1..])

--map :: (a -> b) -> [a] -> [b]
--fmap :: (a -> [b]) => ([a] -> [b])


a = [1, 2, 3, 4, 5]
g x = 2*x
--b = map f a

-- write map by fmap
func  n = [1..n]
fmap' f = concat.map f

myMap f list =
	fmap' (\a -> [f a]) list

b = myMap func a



