

n, s = (int(i) for i in input().split())

aa = [] 

for i in range(n) :
    aa.append(int(input()))

ans = []

x = 1

for i in range(n - 2, -1, -1) :
    ans.append(aa[i] // aa[i + 1])

ans.append(s // aa[0])

for x in ans[::-1] :
    print(x - 1, end=' ')


