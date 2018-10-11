#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "acm"
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

map < int, string > mp;
bool ok[111];

void solve() {

	mp[2] = "(1 + 1 - 10)";
	mp[3] = "(1 + 1 + 1 - 10)";
	mp[4] = "(1 + 1 + 1 + 1 - 10)";
	mp[5] = "(1 + 1 + 1 + 1 + 1 - 10)";
	mp[6] = "(1 + 1 + 1 + 1 + 1 + 1 - 10)";
	mp[7] = "(1 + 1 + 1 + 1 + 1 + 1 + 1 - 10)";
	mp[8] = "(1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 - 10)";
	mp[9] = "(1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 - 10)";
	mp[10] = "(1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1- 10)";
	

	int n, m; cin >> n >> m;
	vi aa(n), bb(m);
	for(int i = 0; i < n; i++) {
		cin >> aa[i];
		ok[aa[i]] = 1;
	}
	for(int i = 0; i < m; i++) cin >> bb[i];
	string s = "";
	for(int i = 2; i < 11; i++) {
		if(ok[i] && sz(s)) {
			s += " * ";
			s += mp[i];
		}
		else if(ok[i]) s += mp[i];
	}
	s += " = 0";
	cout << s << endl;
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