#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "jealous"
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector <string> vs;

const int MAXN = 1e5 + 9;
const int MOD = (int)(1e9 + 7);
const int INF = 1e9;

bool used[MAXN];
ll a, b;
ll p, q;

ll cnt(ll x) {
	return b / x - (a - 1) / x;
}

ll F(ll p_pow, ll q_pow) {
	ll cur_p = 1;
	for(int i = 0; i < p_pow; i++) cur_p *= p;
	ll cur_q = 1;
	for(int i = 0; i < q_pow; i++) {
		if(cur_q > b / q) return 0;
		cur_q *= q;
	}
	ll res = 0;
	if(cur_q <= b / cur_p) res += cnt(cur_q * cur_p);
	if(cur_q * q <= b / cur_p) res -= cnt(cur_q * q * cur_p);
	if(cur_q <= b / (cur_p * p)) res -= cnt(cur_q * p * cur_p);
	if(cur_q * q <= b / (cur_p * p)) res += cnt(cur_q * q * p * cur_p);
	return res;
}

void input() {
	cin >> a >> b >> p >> q;
	ll ans = 0;
	ll lim = 0, cur = p;
	while(cur <= b) {
		lim++;
		if(cur > b / p) break;
		cur *= p;
	}
	cerr << lim << endl;
	for(ll p_pow = 1; p_pow <= lim; p_pow++) {
		for(ll q_pow = 0; q_pow < p_pow; q_pow++) {
			ans += F(p_pow, q_pow);
		}
	}
	cout << ans << endl;
}

void solve() {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif	
	input();
	solve();
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}