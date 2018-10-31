#include<bits/stdc++.h>
using namespace std;

long long bp(long long x, long long p, long long mod) {
    long long res = 1;
    while(p) {
        if(p & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        p /= 2;
    }
    return res;
}

bool ok(int n, int m) {
    long long ans = 0;
    long long p = 1;
    for(int i = 0; i < n; i++) p *= 10;
    for(int i = 1; i < 5; i++) ans = (ans + bp(i, m, p)) % p;
    return ans == 0;
}

int main() {
    int n;
    cin >> n;
    for(int ans = 18; ans >= 0; ans--) {
        if(ok(ans, n)) {
            cout << ans << endl;
            return 0;
        }
    }
    assert(0);
    return 0;
}
