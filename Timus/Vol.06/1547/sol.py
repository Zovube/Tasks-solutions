
def to_i(s):
	res = 0
	p = 1
	s = s[::-1]
	for i in range(0, len(s)):
		cur = ord(s[i]) - ord('a') + 1
		res += p * cur
		p *= 26
	return res

def to_s(x):
	res = ""
	while(x):
		cur = x % 26
		c = chr(ord('a') + (cur - 1 + 26) % 26)
		res += c
		x -= (cur - 1 + 26) % 26
		x //= 26
	res = res[::-1]
	return res

n, m = [int(x) for x in input().split()]
tmp = ""
for i in range(n):
	tmp += 'z'
sum = to_i(tmp)
# print(sum)
step = sum // m
add = sum % m
sum1 = 1
prev = 1
cnt = 0
while(sum >= sum1):
	cur = step
	if add > 0:
		cur += 1
		add -= 1
	sum1 += cur
	print(to_s(prev) + '-' + to_s(sum1 - 1))
	prev = sum1
	cnt += 1
