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
const int MAXN = 1e2 + 9;
const int MOD = 1e9 + 7;
bool used[MAXN];
int dp[MAXN][MAXN];
int n, m;

void input() {                  
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			int tt;
			cin >> tt;
			dp[i][j] = tt;
			if(j >= 0 && i > 0) dp[i][j] = tt + dp[i - 1][j - 1];
			if(i > 0 && j < i) dp[i][j] = max(dp[i][j], tt + dp[i - 1][j]);
		}
	}
	int ans = 0;                                                        
	for(int i = 0; i < n; i++) ans = max(ans, dp[n - 1][i]);
	cout << ans << endl;
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
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif	              
	int t;
	cin >> t;
	while(t--) input();
	return 0;
}
