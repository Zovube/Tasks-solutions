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

const int MAXN = 1e6 + 9;
const int MOD = (int)(1e9 + 7);
const int INF = 100500;

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int n, m, k;
int pp[MAXN];

void dsu_init() {
	for(int i = 0; i < MAXN; i++) pp[i] = i;
}

int dsu_find(int v) {
	if(pp[v] == v) return v;
	else return pp[v] = dsu_find(pp[v]);
}

void dsu_unite(int a, int b) {
	a = dsu_find(a);
	b = dsu_find(b);
	if(a != b) {
		if(rnd() & 1) {
			swap(a, b);
		}
		pp[a] = b;		
	}
}

vi rrsqr[MAXN];
vi rr[MAXN];

void solve() {
	if(k == 1) {
		cout << 3 << endl;
		return;
	}
	dsu_init();
	for(int i = 1; i < MAXN; i++) {
		{
			int curr = k - i % k;
			for(int j = 0; j < sz(rrsqr[curr]); j++) {
				if(dsu_find(rrsqr[curr][j]) != dsu_find(i)) {
					dsu_unite(rrsqr[curr][j], i);
				}
				else {
					cout << i << "\n";
					return;
				}
			}
		}
		{
			int curr = k - (i * 1LL * i) % k;
			for(int j = 0; j < sz(rr[curr]); j++) {
				if(dsu_find(rr[curr][j]) != dsu_find(i)) {
					dsu_unite(rr[curr][j], i);
				}
				else if((rr[curr][j] * 1LL * rr[curr][j] + i) % k != 0) {
					cout << i << "\n";
					return;
				}
			}
		}
		rr[i % k].pb(i);
		rrsqr[(i * 1LL * i) % k].pb(i);
	}
}

void input() {
	cin >> k;
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