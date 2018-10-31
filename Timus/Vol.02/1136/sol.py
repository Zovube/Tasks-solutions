# TLE because of Python

import sys

sys.setrecursionlimit(3000)


left_child = [-1] * 3000
right_child = [-1] * 3000

aa = [0] * 3333

def go (parent, l, r, n) :
    if l >= n or r >= n or l < 0 or r < 0:
        return
    if l > r :
        return
    if parent < 0:
        return

    mid = -1
    for i in range(r - 1, l - 1, -1) :
        if i < 0:
            continue
        if aa[i] < aa[parent] and aa[i + 1] > aa[parent] :
            mid = i
            break
        if aa[l] > aa[parent] :
            break

    right_child[parent] = r
    left_child[parent] = mid
    if mid >= 0 : 
        go(mid, l, mid - 1, n)
        go(r, mid + 1, r - 1, n)
    else :
        go(r, l, r - 1, n)
    return


def out (v) :
    if right_child[v] >= 0 :
        out(right_child[v])
    if left_child[v] >= 0 :
        out(left_child[v])
    print(aa[v])
    return

def main () :
    n = int(input())
    
    if n == 0 :
        exit(0)

    
    print()
    
    for i in range(n) :
        aa[i] = int(input())

    go(n - 1, 0, n - 2, n)
    out(n - 1)


main()
