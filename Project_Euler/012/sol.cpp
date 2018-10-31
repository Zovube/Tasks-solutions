// factorize number and count number of divisors

#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector<string> vs;

const int INF = 100500;
const int MAXN = 1e5 + 9;

void input() {

}

ll f(ll x) {
	ll num = 1;
	ll tt = 2;
	while(tt * tt <= x) {
		ll cc = 0;
		while(x % tt == 0) {
			cc++;
			x /= tt;
		}
		num *= (cc + 1);
		tt++;
	}
	if(x > 1) return num * 2;
	else return num + (x > 1);
}

void solve() {
	int n; 
	cin >> n;
	ll cur = 0;
	while(cur = cur + 1) {
		ll a = cur + 1;
		ll b = cur;
		if(a % 2 == 0) a /= 2;
		if(b % 2 == 0) b /= 2;
		ll cnt = f(a) * f(b);
		if(cnt > n) break;  
	}                                     
	cout << ((cur + 1) * cur) / 2 << endl;
}

int main() {     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif	
	int t;
	cin >> t;
	while(t--) solve();
	TIMESTAMP;
	return 0;
}
