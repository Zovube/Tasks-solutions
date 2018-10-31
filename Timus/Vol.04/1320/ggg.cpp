#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", 1.0*clock()/CLOCKS_PER_SEC)

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
const int MOD = 1e9 + 7;

vi gg[1005];
int deg[MAXN];
int cnt;
bool used[MAXN];

void dfs(int v) {
	used[v] = 1;
	cnt += sz(gg[v]);
	for(auto to : gg[v]) {
		if(!used[to]) {
			dfs(to);
		}
	}
}		

void input() {
	int a, b;         
	while(cin >> a >> b) {
		a--, b--;
		gg[a].pb(b);
		gg[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
}

void solve() {          
	for(int i = 0; i < 1000; i++) {
		if(!used[i] && deg[i]) {
			cnt = 0;
			dfs(i);
			cnt /= 2;
			if(cnt % 2) {
				cout << 0;
				return;
			}
		}
	}
	cout << 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif	
	input();
	solve();
	cout << endl;
	return 0;
}
