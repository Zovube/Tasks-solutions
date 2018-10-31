
n, k = map(int, input().split())

if n == 2:
    print(0)
elif k <= n // 2:
    print(n - k - 2)
else:
    print(k - 3)
