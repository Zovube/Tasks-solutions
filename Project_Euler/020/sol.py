# big numbers ? time for python!

for j in range (int(input())):
	n = int(input())

	f = 1

	for i in range (1, n + 1):
		f = f * i

	ans = 0

	for x in str(f):
		ans += int(x)

	print(ans)
