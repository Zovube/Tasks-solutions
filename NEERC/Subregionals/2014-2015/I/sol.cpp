#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "instruction"
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

const int MAXN = 1e3 + 9;
const int MOD = (int)(1e9 + 7);
const int INF = 1e9;

int to[MAXN];
vvi gg;
int n, m;
bool isStation[MAXN];
vector < int > path[MAXN];
map < char, int > id;
int pp[MAXN];
int pos[MAXN];
int need[MAXN][MAXN];
int goal[MAXN];

void go(int v) {
	for(auto to : gg[v]) {
		pp[to] = v;
		go(to);
	}
	if(!isStation[v]) {
		to[v] = min(gg[v][0], gg[v][1]);
	}
}

void input() {
	cin >> n;
	gg.resize(n);
	for(int i = 0; i < n; i++) {
		char c; cin >> c;
		int p; cin >> p;
		if(p == 0) continue;
		p--;
		gg[p].pb(i);
		if(c == 'p') {
			char c; cin >> c;
			id[c] = i;
			isStation[i] = 1;
		}
	}
	pp[0] = -1;
	go(0);
	for(int i = 0; i < n; i++) {
		if(isStation[i]) {
			vi aa;
			int v = i;
			while(v != -1) {
				aa.pb(v);
				v = pp[v];
			}
			reverse(all(aa));
			for(int j = 0; j < sz(aa) - 1; j++)
				need[aa[j]][i] = aa[j + 1]; 
		}
	}
}

bool cmp(pii a, pii b) {
	return a.se < b.se;
}

void solve() {
	set < pii > qq;
	
	cin >> m;
	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		char c; cin >> c;
		goal[i] = id[c];
		qq.insert({x, i});
		pos[i] = 0;
	}
	
	vpii ans;
	
	while(!qq.empty()) {
		auto tmp = *qq.begin();
		qq.erase(tmp);
		int v = tmp.se;
		if(to[pos[v]] != need[pos[v]][goal[v]]) {
			to[pos[v]] ^= gg[pos[v]][0] ^ gg[pos[v]][1];
			ans.pb({pos[v] + 1, tmp.fi + 1});
		}
		pos[v] = need[pos[v]][goal[v]];
		if(pos[v] != goal[v]) 
			qq.insert({tmp.fi + 1, tmp.se});
	}
	
	sort(all(ans), cmp);
	cout << sz(ans) << endl;
	for(auto x : ans) 
		cout << x.fi << ' ' << x.se << endl;
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