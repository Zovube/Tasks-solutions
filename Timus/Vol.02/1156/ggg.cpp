#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>
#define TASK "zak"
#define pb push_back
#define fi first
#define se second
#define sz(a) (int)(a.size())
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) (void)42
#endif

// every true-boy doesn't read statement!

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef long double ld;
typedef vector < vector < int > > vvi;
typedef vector <int> vi;

const int MAXN = 1e5 + 9;

vvi gg;
int n, m;
int col[MAXN];
bool used[MAXN];
int deg[MAXN];

bool dfs(int v, int color) {
	col[v] = color;
	used[v] = 1;
	bool h = 1;
	for(auto to : gg[v]) {
		if(used[to]) {
			if(col[to] == col[v]) return 0;
		}
		else h &= dfs(to, 3 - color);
	}
	return h;
}

void input() {
	cin >> n >> m;
	gg.resize(2 * n);
	for(int i = 0; i < m; i++) {	
		int a, b;
		cin >> a >> b;
		a--, b--;
		deg[a]++;
		deg[b]++;
		gg[a].pb(b);
		gg[b].pb(a);
	}	
}

vi a, b, c;

void solve() {
	for(int i = 0; i < 2 * n; i++) {
		if(!used[i] && deg[i]) {
			if(dfs(i, 1)) {
						}
			else {
				cout << "IMPOSSIBLE";
				return;
			}
		}
	}
	for(int i = 0; i < 2 * n; i++) {
		if(col[i] == 1) {
			a.pb(i + 1);
		}
		else if(col[i] == 2) b.pb(i + 1);
		else c.pb(i + 1);
	}
	if(max(sz(a), sz(b)) > n) {
		cout << "IMPOSSIBLE;;";
		return;
	}
	for(int i = 0; i < sz(c); i++) {
		if(sz(a) < n) a.pb(c[i]);
		else b.pb(c[i]);
	}
	assert(sz(a) == sz(b) && sz(a) == n);
	for(auto x : a) cout << x << ' ';
	cout << endl;
	for(auto x : b) cout << x << ' ';	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	assert(freopen("xxx.in", "r", stdin));
	assert(freopen("xxx.out", "w", stdout));
#else
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
#endif
	input();
	solve();
	return 0;
}