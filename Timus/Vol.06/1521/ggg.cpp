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
const int INF = 100500;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int n, m, k;
int tt[4 * MAXN];

void build(int v, int l, int r) {
	if(l == r - 1) {
		tt[v] = 1;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	tt[v] = tt[v * 2 + 1] + tt[v * 2 + 2];
}

int sum(int v, int l, int r, int ql, int qr) {
	if(ql >= r || qr <= l) return 0;
	if(ql <= l && qr >= r) return tt[v];
	int m = (l + r) / 2;
	int a = sum(v * 2 + 1, l, m, ql, qr);
	int b = sum(v * 2 + 2, m, r, ql, qr);
	return a + b;
}

int query(int v, int l, int r, int issuf, int val) {
	if(l == r - 1) {
		return l;
	}
	int m = (l + r) / 2;
	if(issuf) {
		if(tt[v * 2 + 2] >= val) return query(v * 2 + 2, m, r, issuf, val);
		else return query(v * 2 + 1, l, m, issuf, val - tt[v * 2 + 2]);
	}
	else {
		if(tt[v * 2 + 1] >= val) return query(v * 2 + 1, l, m, issuf, val);
		else return query(v * 2 + 2, m, r, issuf, val - tt[v * 2 + 1]);
	}
}

void upd(int v, int l, int r, int pp) {
	if(l == r - 1) {
		tt[v] = 0;
		return;
	}
	int m = (l + r) / 2;
	if(pp >= m) upd(v * 2 + 2, m, r, pp);
	else upd(v * 2 + 1, l, m, pp);
	tt[v] = tt[v * 2 + 1] + tt[v * 2 + 2];
}

void input() {
	cin >> n >> k;
}

void solve() {
	build(0, 0, n);
	int pos = 0;
	for(int i = 0; i < n; i++) {
		int cur = k % (n - i);
		if(cur == 0) cur = (n - i);
		int ss = sum(0, 0, n, pos, n);
		if(ss >= cur) {
			pos = query(0, 0, n, 1, ss - cur + 1);
		}
		else pos = query(0, 0, n, 0, cur - ss);
		cout << pos + 1 << ' ';
		upd(0, 0, n, pos);
	}
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