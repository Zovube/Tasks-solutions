#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "digits"
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

ll nxt(ll x) {
	vi aa;
	while(x) {
		aa.pb(x % 10);
		x /= 10;
	}
	bool canSub = 0;
	bool ok = 0;
	ll sum = 0;
	for(int i = 0; i < sz(aa); i++) {
		if(aa[i] != 9 && canSub) {
			aa[i]++;
			sum--;
			for(int j = 0; j < i; j++) {
				int cur = min(9LL, sum);
				aa[j] = cur;
				sum -= cur;
			}
			ok = 1;
			break;
		}
		if(aa[i] && !canSub) canSub = 1;
		sum += aa[i];
	}
	if(!ok) {
		aa.pb(1);
		sum--;
		for(int j = 0; j < sz(aa) - 1; j++) {
			int cur = min(9LL, sum);
			aa[j] = cur;
			sum -= cur;
		}
	}
	assert(sum == 0);
	reverse(all(aa));
	ll res = 0;
	for(int i = 0; i < sz(aa); i++)
		res = res * 10 + aa[i];
	assert(res > 0);
	return res;
}

ll f(ll sum, ll n) {
	ll res = 0;
	ll cur = 0;
	vi aa;
	while(sum) {
		ll tmp = min(9LL, sum);
		aa.pb(tmp);
		sum -= tmp;
	}
	reverse(all(aa));
	for(int i = 0; i < sz(aa); i++) 
		cur = cur * 10 + aa[i];
	for(int i = 0; i < n; i++) {
		res += cur;
		assert(res > 0);
		cur = nxt(cur);		
	}
	return res;
}

void input() {
	ll n; cin >> n;
	if(n == 1) {
		cout << 1;
		return;
	}
	ll ans = LONG_LONG_MAX;
		for(ll sum = min(9LL, n - 1); sum < 30; sum++) {
			ans = min(ans, f(sum, n));
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