#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "defense"
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

void input() {

}

void solve() {
	int w, h; cin >> w >> h;
	int n; cin >> n;
	vi aa(n), bb(n);
	for(int i = 0; i < n; i++) {
		cin >> aa[i] >> bb[i];
	}
	aa.pb(0), bb.pb(0), aa.pb(w + 1), bb.pb(h + 1);
	sort(all(aa)), sort(all(bb));
	int dx = 0, dy = 0;
	for(int i = 0; i < sz(aa) - 1; i++) {
		dx = max(dx, aa[i + 1] - aa[i]);
		dy = max(dy, bb[i + 1] - bb[i]);
	}
	cout << (dx - 1) * (dy - 1) << endl;
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