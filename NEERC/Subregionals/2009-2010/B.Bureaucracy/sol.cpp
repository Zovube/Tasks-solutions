#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "bureau"
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

bool used[MAXN];

void input() {
	int n;
	cin >> n;
	vi aa(n);
	for(int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s;
		if(s[0] == 'd') aa[i] = n;
		else {
			cin >> x;
			aa[i] = x - 1;
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		if(!used[i] && aa[i] < n) used[aa[i]] = 1;
	}
	vi ans;
	for(int i = 0; i < n; i++) 
		if(!used[i]) ans.pb(i);
	cout << sz(ans) << endl;
	for(auto x : ans) cout << x + 1 << ' ';
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