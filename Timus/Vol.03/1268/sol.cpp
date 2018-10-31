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

    ll get_generator(ll prime) {
        vector < ll > fact;
        ll phi = prime - 1, n = phi;
        for(ll i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                fact.push_back(i);
                while(n % i == 0)
                    n /= i;
            }
        }
        if(n > 1) fact.push_back(n);
        for(ll res = prime - 1; res > 1; res--) {
            bool ok = 1;
            for(ll i = 0; i < (ll)fact.size() && ok; i++) {
                ok &= (bin_pow(res, phi / fact[i], prime) != 1);
            }   
            if(ok) 
                return res;
        }
        return -1;
    }

};

namespace nt = Number_Theory;

int main() {
    int tests;
    cin >> tests;
    while(tests--) {
        ll n;
        cin >> n;
        cout << nt::get_generator(n) << endl;
    }
    return 0;
}
