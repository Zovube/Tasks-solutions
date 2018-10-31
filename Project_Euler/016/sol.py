# python rules


for i in range (int(input())):
	x = str(2 ** int(input()))
	ans = 0
	for j in range(0, len(x)):
		ans += int(x[j])
	print(ans)



