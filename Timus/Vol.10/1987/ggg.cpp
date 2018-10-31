#pragma GCC optimize("O3") 
#define TASK ""
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
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
const int INF = INT_MIN;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int n, m;
int len[MAXN];

void input() {
	cin >> n;
	vpii aa;
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		len[i + 1] = r - l + 1;
		aa.pb({l, -(i + 1)});
		aa.pb({r, (i + 1)});
	}
	cin >> m;
	set <pii> st;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		aa.pb({x, 0});
	}
	sort(all(aa));
	for(int i = 0; i < sz(aa); i++) {
		pii cur = aa[i];
		if(cur.se == 0) {
			if(st.empty()) cout << -1;
			else cout << st.begin()->se;
			cout << '\n';
		}
		else if(cur.se > 0) {
			st.erase({len[cur.se], cur.se});
		}
		else {
			st.insert({len[-cur.se], -cur.se});
		}
	}
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
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
#endif	
	input();
	solve();
	return 0;
}