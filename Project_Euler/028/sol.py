# python + maths are wonderful


for j in range(int(input())):
	
	n = int(input())
	ans = ((((2 * n + 3) * (n + 2) * (n + 1) // 6))  - (((2 + n + 1) // 2) * (n // 2 + 1)) * 2 + (n // 2 + 1)) * 2 - ((2 + n - 1) // 2) * (n // 2) * 6 - 3 

	print(ans % (10 ** 9 + 7))
