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
int n, m;
int tt[4 * MAXN];
int aa[MAXN];

void build(int v, int l, int r) {
	if(l == r - 1) {
		tt[v] = l + 1;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	tt[v] = max(tt[v * 2 + 1], tt[v * 2 + 2]);
}

void update(int v, int l, int r, int pos) {
	if(l == r - 1) {
		tt[v] = 0;
		return;
	}
	int m = (l + r) / 2;
	if(pos >= m) update(v * 2 + 2, m, r, pos);
	else update(v * 2 + 1, l, m, pos);
	tt[v] = max(tt[v * 2 + 1], tt[v * 2 + 2]);
}

int query(int v, int l, int r, int ql, int qr) {
	if(ql >= r || qr <= l) return 0;
	if(ql <= l && qr >= r) return tt[v];
	int m = (l + r) / 2;
	int a = query(v * 2 + 1, l, m, ql, qr);
	int b = query(v * 2 + 2, m, r, ql, qr);
	return max(a, b);
}

void input() {
	cin >> n;
	build(0, 0, n);
	for(int i = 0; i < n; i++) cin >> aa[i];
	for(int i = 0; i < n - 1; i++) {
		if(aa[i + 1] < aa[i] && aa[i + 1] != query(0, 0, n, 0, aa[i] - 1)) {
			cout << "Cheater";
			return;
		}
		update(0, 0, n, aa[i] - 1);
	}
	cout << "Not a proof";
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