#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    int T; cin >> T;
    for(int test = 1; test <= T; test++) {
        
        int n; cin >> n;
        vector < int > aa(n);
        for(int i = 0; i < n; i++) cin >> aa[i];
        sort(aa.begin(), aa.end());

        long long mod = 1e9 + 7;
        long long ans = 0;

        vector < long long > bp(n + 1);
        bp[0] = 1;
        for(int i = 1; i <= n; i++) 
            bp[i] = (bp[i - 1] * 2) % mod;

        for(int i = 0; i < n; i++) {
            ans = (ans + (aa[i] * bp[i]) % mod) % mod;
            ans = (ans - (aa[i] * bp[n - 1 - i]) % mod + mod) % mod;
        }

        cout << "Case #" << test << ": " << ans << endl;
    }

    return 0;
}
