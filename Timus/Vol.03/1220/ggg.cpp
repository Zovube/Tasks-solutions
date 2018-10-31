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

/*typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector <string> vs;

const int MOD = (int)(1e9 + 7);
const int INF = 100500;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};*/
const int MAXN = 1e5 + 9;

int n, m;

short st[1005];
int cnt = 0;
short pp1[MAXN];
;
int b;
short a;
string s;
int x;

void input() {
	cin >> n;
	cerr << sizeof(pp2) << endl;
	for(int i = 0; i < n; i++) {
		cin >> s;
		if(s == "POP") {
			cin >> x;
			cout << pp2[st[x]] << "\n";
			st[x] = pp1[st[x]];
		}
		else {
			cin >> a >> b;
			cnt++;
			pp1[cnt] = st[a];
			pp2[cnt] = b;
			st[a] = cnt;
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