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

int n, m;
int pp[MAXN];

struct edge {
	int u, v, w;
};

bool cmp(edge a, edge b) {
	if(a.w < b.w) return 1;
	if(a.w > b.w) return 0;
	return 0;
}

vector < edge > ee;

int find_p(int v) {
	if(pp[v] == v) return v;
	return pp[v] = find_p(pp[v]);
}

bool unite(int a, int b) {
	if(find_p(a) != find_p(b)) {
		a = find_p(a);
		b = find_p(b);
		if(rand() & 1) swap(a, b);
		pp[a] = b;
		return 1;
	}
	return 0;
}

void input() {                  
	cin >> n >> m;
	ee.resize(m);
	for(int i = 0; i < m; i++) {
		cin >> ee[i].u >> ee[i].v >> ee[i].w;
	}
}

void solve() {          
	for(int i = 1; i <= n; i++) pp[i] = i;
	sort(all(ee), cmp);
	vector < edge > ans;
	for(int i = 0; i < m; i++) {
		if(unite(ee[i].v, ee[i].u)) ans.pb(ee[i]);
   	}
   	assert(sz(ans) == n - 1);              
   	sort(all(ans), cmp);
   	cout << ans[n - 2].w << endl << sz(ans) << endl;
   	for(auto x : ans) cout << x.v << ' ' << x.u << endl;
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
	return 0;
}
