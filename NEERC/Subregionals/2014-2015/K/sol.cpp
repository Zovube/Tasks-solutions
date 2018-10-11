#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK ""
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

const int MAXN = 1e3 + 9;
const int MOD = (int)(1e9 + 7);
const int INF = 1e9;
const int MAXQ = 250 + 9;

int dp1[MAXQ][MAXQ];
int t, n;
int dp[MAXN][MAXQ];
int qq[MAXN], xx[MAXN];

void add(int &x, int y) {
	x += y;
	if(x > MOD) x -= MOD;
}

void precDp1() {
	dp[0][1] = 1;
	for(int i = 0; i < MAXQ; i++) {
		for(int j = 0; j < MAXQ; j++) {
			for(int k = i + t + 1; k < MAXQ; k++) {
				add(dp[k][j + 1], dp[i][j]); 
			}
		}
	}
}

void input() {
	cin >> n >> t;
	for(int i = 0; i < n; i++) cin >> qq[i] >> xx[i];
}

void solve() {
	for(int i = 0; i < n - 1; i++) { 
		for(int j = 0; j <= qq[i]; j++) { 
			for(int k = 0; k <= qq[i + 1]; k++) {
				if(j == 0) {
					add(dp[i + 1][k], dp[i][j]);
					continue;
				}
				if(k == 0) {
					int cur = (dp[i][j] * 1LL * dp1[max(0, qq[i] + k - t - i)][xx[i]]);
					add(dp[i + 1][k], cur);

				}
				
				int cur = (dp[i][j] * 1LL * dp1[max(0, qq[i] + k - t - i)][xx[i]]);
				add(dp[i + 1][k], cur);
			}
		}
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