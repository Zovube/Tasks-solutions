
fact = [1] * 45

for i in range(2, 45) :
    fact[i] = fact[i - 1] * i

def c (n, k) :
    return fact[n] // fact[n - k] // fact[k]

n, a, b = map(int, input().split())

print(c(n + a, n) * c(n + b, n))
