main = print (length c)

a = [100..999]
b = [100..999]
c = [x*y|x<-a, y<-b]

judge num
	tostring