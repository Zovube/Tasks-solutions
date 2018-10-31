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

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int n, m;

void input() {
	n = rnd() % 250000 + 1;
	cout << n << "\n";
	for(int i = 0; i < n; i++) {
		cout << rnd() << "\n";
	}
	TIMESTAMP;
}

void solve() {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	//freopen("xxx.in", "r", stdin);
	freopen("xxx.in", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
#endif	
	input();
	solve();
	return 0;
}