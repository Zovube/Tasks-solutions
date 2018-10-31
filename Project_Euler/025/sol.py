# 3 seconds for python, why not


ans = [0 for i in range(0, 5003)]


for x in range(2, 5001):
	a = b = 1
	c = 2
	h = 1
	for i in range (1, 100000):
		(a, b, c) = (b, c, b + c)
		if len(str(c)) >= x:
			ans[x] = i + 3
			x += 1
			if x > 5000:
				h = 0
				break
	if h == 0:
		break



for j in range (int(input())):
	print(ans[int(input())])


