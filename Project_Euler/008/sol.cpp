// simple brute-force

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

string s;

void input() {

}

void solve() {
	int n, k;
	cin >> n >> k;
	cin >> s;
	ll ans = 0;
	for(int i = 0; i < sz(s) - k; i++) {
		ll cur = 1;
		for(int j = 0; j < k; j++) cur *= (s[j + i] - '0');
		ans = max(ans, cur);
	}
	cout << ans << endl;
}

int main() {     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif	
	input();
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
