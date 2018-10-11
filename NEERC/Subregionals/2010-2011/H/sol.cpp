#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "horrible"
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector <string> vs;

const int MAXN = 1e5 + 9;
const int MOD = (int)(1e9 + 7);
const int INF = 1e9;

int n;

void input() {
	cin >> n;
}

void solve() {
	vpii ans;
	int lst = -2;
	for(int i = 0; i < n; i++) {
		if(i == 0 && n > 1 && lst != -1) {
			ans.pb({i + 2, -(i + 1)});
			lst = -1;
		}
		if(lst != 0) {
			ans.pb({i + 1, 0});
			lst = 0;
		}
		for(int j = 0; j < i; j++) {
			if(lst != 1) {
				ans.pb({j + 1, (i + 1)});
				lst = 1;
			}
			if(i != n - 1 && lst != -1) {
				ans.pb({j + 1, -(i + 2)});			
				lst = -1;
			}
		}
		if(i != n - 1) {
			if(lst != 1) {
				ans.pb({i + 2, (i + 1)});
				lst = 1;
			}
			if(lst != -1) {
				ans.pb({i + 1, -(i + 2)});
				lst = -1;
			}
		}
		for(int j = i + 2; j < n; j++) {
			if(lst != 1) {
				ans.pb({j + 1, (i + 1)});
				lst = 1;
			}
			if(i != n - 1 && lst != -1) {
				ans.pb({j + 1, -(i + 2)});
				lst = -1;
			}
		}
	}
	cout << sz(ans) << endl;
	for(auto x : ans) cout << x.fi << ' ' << x.se << endl;
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