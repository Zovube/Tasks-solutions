
def c(n, k) :
    return fact[n] // fact[n - k] // fact[k]

fact = [0] * 101

fact[0] = 1

for i in range(1, 101):
    fact[i] = fact[i - 1] * i

B, R, Y = map(int, input().split())

n = int(input())

b_cnt, r_cnt, y_cnt = 0, 0, 0

for i in range(n):
    name = input()
    
    if name[0] == 'B':
        b_cnt += 1
    if name[0] == 'R':
        r_cnt += 1
    if name[0] == 'Y':
        y_cnt += 1

print(c(B, b_cnt) * c(R, r_cnt) * c(Y, y_cnt))


