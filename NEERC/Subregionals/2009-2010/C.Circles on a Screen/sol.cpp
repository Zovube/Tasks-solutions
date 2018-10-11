#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "circles"
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
	int w, h, n;
	cin >> w >> h >> n;
	vi xx(n), yy(n), rr(n);
	for(int i = 0; i < n; i++) {
		cin >> xx[i] >> yy[i] >> rr[i];
	}
	int ans = w * h;
	for(int i = 0; i < h; i++) {
		vector < pii > aa;
		for(int j = 0; j < n; j++) {
			if(abs(i - yy[j]) > rr[j]) continue;
			int add = floor(sqrt(rr[j] * rr[j] - (i - yy[j]) * (i - yy[j])));
			int cur_l = max(0, xx[j] - add);
			int cur_r = min(w - 1, xx[j] + add);
			aa.pb({cur_l, -1});
			aa.pb({cur_r + 1, 1});
	 	}
	 	sort(all(aa));
	 	int res = 0;
	 	int cnt = 0;
	 	for(int j = 0; j < sz(aa); j++) {
			if(cnt) res += aa[j].fi - aa[j - 1].fi;
			cnt -= aa[j].se;
	 	}
	 	ans -= res;
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