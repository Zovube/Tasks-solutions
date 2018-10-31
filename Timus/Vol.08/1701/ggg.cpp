#pragma GCC optimize("O3") 
#define TASK ""
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define cerr cout
#define se second
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
typedef vector <string> vs;

const int MAXN = 1e5 + 9;
const int MOD = (int)(1e9 + 7);
const int INF = 100500;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int n, m;
bool cc[MAXN];
bool tt[MAXN];
bool used[MAXN];
int ans[MAXN];
vpii gg[MAXN];

void input() {
	cin >> n >> m; 
}

void cry(int c) {
	cout << "Impossible after " << c << " statements";
	exit(0);
}

void print_graph() {
	cerr << endl;
	cerr << "Graph IS : " << endl;
	for(int i = 0; i < n; i++) {
		cerr << "Vertex # " << i << " :  ans[v] = " << ans[i] << endl;
		for(auto x : gg[i]) cerr << "Edge to " << x.fi << " with length = " << x.se << endl;
	}
	cerr << endl;
}

bool dfs(int v) {
	cerr << "DFS at " << v << endl;
	print_graph();
	used[v] = 1;
	tt[v] = 1;
	bool h = 1;
	for(int i = 0; i < sz(gg[v]); i++) {
		int to = gg[v][i].fi;
		cerr << to << " <- to | used[to] -> " << used[to] << endl;
		if(!used[to]) {
			ans[to] = ans[v] - gg[v][i].se;
			if(ans[to] < 0) {
				h = 0;
			}
			h *= dfs(to);
		}
		else {
			if(ans[to] != ans[v] - gg[v][i].se) {
				cerr << "ALERT " << to << ' ' << v << ' ' << ans[to] << ' ' << ans[v] - gg[v][i].se << endl;
				h = 0;
			}
		} 
	}
	return h;
}

void solve() {
	cc[0] = 1;
	for(int i = 0; i < m; i++) {
		cerr << "Statement # " << i << " : " << endl;
		print_graph();
		int a, b, c;
		cin >> a >> b >> c;
		if(cc[a]) {
			if(cc[b]) {
				if(ans[b] != ans[a] - c) {
					cry(i + 1);
				}
			}
			else {
				ans[b] = ans[a] - c;
				if(!dfs(b) || ans[b] < 0) {
					cry(i + 1);
				}
				cc[b] = 1;
			}
		}
		else if(cc[b]) {
			swap(a, b);
			c *= -1;
			if(cc[b]) {
				if(ans[b] != ans[a] - c) {
					cry(i + 1);
				}
			}
			else {
				ans[b] = ans[a] - c;
				cerr << "ans[b] = " << ans[b] << endl;
				if(!dfs(b) || ans[b] < 0) {
					cry(i + 1);
				}
				cc[b] = 1;
			}
		}
		else {
			if(tt[b]) {
				if(ans[b] != ans[a] - c) {
					cry(i + 1);
				}
			}
			else {
				tt[b] = 1;
				ans[b] = ans[a] + c;
				gg[a].pb({b, c});
				gg[b].pb({a, -c});
			}
		}	
	}
	cout << "Possible\n";
	for(int i = 0; i < n; i++) cout << ans[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
#endif	
	input();
	solve();
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}