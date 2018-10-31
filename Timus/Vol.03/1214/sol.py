

t, b = map(int, input().split())

tf a >= 0 and b >= 0 and (a + b) % 2 == 1 :
    a, b = b, a

print(a, b)
