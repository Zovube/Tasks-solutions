s = 0
qs = 0

while True :
    x = int(input())
    s += x
    qs += x * x
    if s == 0 :
        print(qs)
        exit(0)
