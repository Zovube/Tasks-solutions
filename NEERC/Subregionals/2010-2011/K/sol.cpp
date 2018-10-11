#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "kitchen"
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

const int MAXN = 18;
const int MOD = (int)(1e9 + 7);
const ld INF = 1e18;
const int LIM = 30;

ld xx[MAXN], yy[MAXN];
ld dp[MAXN][1 << MAXN];
int n;
ld w, h;
ld xR, yR;
bool was[MAXN][1 << MAXN];
bool used[111][111];
ld dd[111][111];

ld dist(int idA, int idB = -1) {
	if(idB == -1) 
		return sqrt((xx[idA] - xR) * (xx[idA] - xR) + (yy[idA] - yR) * (yy[idA] - yR));
	return sqrt((xx[idA] - xx[idB]) * (xx[idA] - xx[idB]) + (yy[idA] - yy[idB]) * (yy[idA] - yy[idB]));
}

ld dst(ld x1, ld y1, ld x2, ld y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld getDist(int a, int b) {
	if(used[a][b]) return dd[a][b];
	ld res = INF;
	{
		ld x1 = xx[a], x2 = xx[b];
		ld X = max(yy[a], yy[b]) - min(yy[a], yy[b]);
		ld l = 0, r = X;
		for(int i = 0; i < LIM; i++) {
			ld m1 = (l + l + r) / 3.;
			ld m2 = (l + r + r) / 3.;
			ld f1 = dst(x1, 0., 0., m1) + dst(0., m1, x2, X);
			ld f2 = dst(x1, 0., 0., m2) + dst(0., m2, x2, X);
			if(f1 < f2) r = m2;
			else l = m1;
		}
		res = min(res, dst(x1, 0., 0., l) + dst(0., l, x2, X));
	}
	{
		ld x1 = yy[a], x2 = yy[b];
		ld X = max(xx[a], xx[b]) - min(xx[a], xx[b]);
		ld l = 0, r = X;
		for(int i = 0; i < LIM; i++) {
			ld m1 = (l + l + r) / 3.;
			ld m2 = (l + r + r) / 3.;
			ld f1 = dst(x1, 0., 0., m1) + dst(0., m1, x2, X);
			ld f2 = dst(x1, 0., 0., m2) + dst(0., m2, x2, X);
			if(f1 < f2) r = m2;
			else l = m1;
		}
		res = min(res, dst(x1, 0., 0., l) + dst(0., l, x2, X));
	}
	{
		ld x1 = w - xx[a], x2 = w - xx[b];
		ld X = max(yy[a], yy[b]) - min(yy[a], yy[b]);
		ld l = 0, r = X;
		for(int i = 0; i < LIM; i++) {
			ld m1 = (l + l + r) / 3.;
			ld m2 = (l + r + r) / 3.;
			ld f1 = dst(x1, 0., 0., m1) + dst(0., m1, x2, X);
			ld f2 = dst(x1, 0., 0., m2) + dst(0., m2, x2, X);
			if(f1 < f2) r = m2;
			else l = m1;
		}
		res = min(res, dst(x1, 0., 0., l) + dst(0., l, x2, X));
	}
	{
		ld x1 = h - yy[a], x2 = h - yy[b];
		ld X = max(xx[a], xx[b]) - min(xx[a], xx[b]);
		ld l = 0, r = X;
		for(int i = 0; i < LIM; i++) {
			ld m1 = (l + l + r) / 3.;
			ld m2 = (l + r + r) / 3.;
			ld f1 = dst(x1, 0., 0., m1) + dst(0., m1, x2, X);
			ld f2 = dst(x1, 0., 0., m2) + dst(0., m2, x2, X);
			if(f1 < f2) r = m2;
			else l = m1;
		}
		res = min(res, dst(x1, 0., 0., l) + dst(0., l, x2, X));
	}
	dd[a][b] = res;
	used[a][b] = 1;
	//cerr << a <<  ' ' << b << ' ' << fixed << setprecision(10) << res << endl;
	return res;
}

ld f(int v, int mask) {
	if(was[v][mask]) {
		return dp[v][mask];
	}
	was[v][mask] = 1;
	ld &res = dp[v][mask];
	res = INF;
	if(mask == (1 << n) - 1) {
		res = min(xx[v], w - xx[v]);
		res = min(res, min(yy[v], h - yy[v]));
		return res; 
	}
	for(int i = 0; i < n; i++) {
		if(mask & (1 << i)) continue;
		res = min(res, f(i, mask | (1 << i)) + getDist(v, i));
	}
	return res;
}

void input() {
	cin >> w >> h;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> xx[i] >> yy[i];
	cin >> xR >> yR;
}

void solve() {
	ld ans = INF;
	for(int i = 0; i < n; i++) {
		ans = min(ans, f(i, (1 << i)) + dist(i));
	}
	cout << fixed << setprecision(10) << ans << endl;
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