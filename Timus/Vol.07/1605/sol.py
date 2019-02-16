n = int(input())

aa = [0] * n

aa[0] = 0
aa[1] = 1
for i in range(2, n):
	aa[i] = (aa[i - 1] + aa[i -2 ]) / 2
	print(aa[i])