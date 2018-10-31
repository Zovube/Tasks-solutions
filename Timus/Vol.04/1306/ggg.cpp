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

const int MAXN = (250000) / 2 + 1000;
const int MOD = (int)(1e9 + 7);
const int INF = 100500;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int n, m;

void input() {
	int x;
	cin >> n;
	vector < unsigned int > aa;
	aa.reserve(MAXN);
	int i;
	for(i = 0; i < n / 2 + 1; i++) {
		cin >> x;
		aa.pb(x);
		push_heap(all(aa));
	}
	for(; i < n; i++) {
		cin >> x;
		aa.pb(x);
		push_heap(all(aa));
		pop_heap(all(aa));
		aa.pop_back();
	}
	double a = aa.front();
	if(n % 2 == 0) {
		pop_heap(all(aa));
		aa.pop_back();
		a = double(aa.front()) / 2 + a / 2;
	}		
	cout << fixed << setprecision(1) << (a);
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