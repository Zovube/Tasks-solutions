

n = int(input())

aa = []

for i in range(n):
    x = int(input())
    aa.append(x)

aa = sorted(aa)

for i in range(2, n):
    if aa[i - 1] + aa[i - 2] > aa[i]:
        print(aa[i - 2], aa[i - 1], aa[i])
        break

print(0, 0, 0)

