
fact = [0] * 20

fact[0] = 1
for i in range(1, 20):
    fact[i] = fact[i - 1] * i

while True:
    x = int(input())
    if x == -1:
        break
    print((2 ** (x - 1) - 1) * fact[x] + 1)
