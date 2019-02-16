#include<bits/stdc++.h>
using namespace std;

int main() {

    auto myPow = [&] (int x, int pp, int mod) {
        int res = 1;
        while(pp) {
            if(pp & 1) res = (res * x) % mod;
            x = (x * x) % mod;
            pp /= 2;
        }
        return res;
    };


    int n, k, m; cin >> n >> m >> k;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        int cur = myPow(x, m, k);
        if(!cur) ans++;
    }

    cout << ans << endl;
    return 0;
}
