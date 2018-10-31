import fractions

n = int(input())

sump = 0
sumq = 1

for i in range(n) :
    print(sumq + 1)
    tmp = sumq + 1

    nsump = sump * tmp + sumq
    nsumq = sumq * tmp

    gcd = fractions.gcd(nsump, nsumq)

    nsump //= gcd
    nsumq //= gcd

    sump, sumq = nsump, nsumq
    
