// simple dp

#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", 1.0*clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector<string> vs;

const int INF = 1e9;
const int MAXN = 500 + 9;
const int MOD = 1e9 + 7;
bool used[MAXN];
int n, m;
ll dp[MAXN][MAXN];

void precalc() {                  
	for(int i = 1; i < MAXN; i++) {
		dp[i][0] = dp[0][i] = 1;
	}
	for(int i = 1; i < MAXN; i++) {
		for(int j = 1; j < MAXN; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}                          
}

void solve() {          
	cin >> n >> m;
	cout << dp[n][m] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif	
	precalc();
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
