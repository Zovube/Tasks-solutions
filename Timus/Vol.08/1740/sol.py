 
l, k, h = map(int, input().split())

print(h * (l // k))
print(h * ((l + k - 1) // k))
