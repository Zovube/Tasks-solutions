#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

namespace Number_Theory {

    ll phi(ll n) {
        ll ans = n;
        for(ll i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                while(n % i == 0) {
                    n /= i;
                }
                ans -= ans / i;
            }
        }
        if(n > 1) {
            ans -= ans / n;
        }
        return ans;
    }

    ll bin_pow(ll x, ll p, ll mod) {
        ll res = 1;
        while(p) {
            if(p & 1) { 
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            p /= 2;
        }
        return res;
    }

    ll ext_gcd(ll a, ll b, ll & x, ll & y) {
        if(a == 0) {
            x = 0, y = 1;
            return b;
        }
        ll x1, y1;
        ll d = ext_gcd(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }

    vector < int > find_all_reverse (int n) {
        vector < int > rev(n);
        rev[1] = 1;
        for(int i = 2; i < n; i++) {
            rev[i] = (n - (n / i) * rev[n % i] % n) % n;
        }
        return rev;
    }

};

namespace nt = Number_Theory;

int main() {
    ll A, N;
    cin >> A >> N;
    if(__gcd(A, N) != 1) {
        cout << 0 << endl;
        return 0;
    }
    ll phi = Number_Theory::phi(N);

    ll ans = INT_MAX;

    for(ll i = 2; i * i <= phi; i++) {
        if(phi % i == 0) {
            if(Number_Theory::bin_pow(A, i, N) == 1) {
                ans = min(ans, i);
            }
            if(Number_Theory::bin_pow(A, phi / i, N) == 1)
                ans = min(ans, phi / i);
        }
    }

    cout << ans << endl;

    return 0;
}
