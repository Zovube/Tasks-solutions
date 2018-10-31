// brute-force with memorization and prefix maximum
// P.S. AC without memorization -> weak tests???

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
const int MAXN = 5e6 + 9;
const int MOD = 1e9 + 7;

int n, m;
int dp[MAXN];
int ans[MAXN];

int f(ll x) {
	if(x < MAXN && dp[x]) return dp[x];       
	if(x == 1) return 0;
	if(x & 1) return f((x << 1) + 1 + x) + 1;
	else return f(x >> 1) + 1;
}

void precalc() {
	for(int i = 1; i < MAXN; i++) {
		dp[i] = f(i);
	}         
	ans[1] = 1;
	for(int i = 1; i < MAXN; i++) {
		if(dp[i] >= dp[ans[i - 1]]) {
			ans[i] = i;
		}
		else {
			ans[i] = ans[i - 1];
		}
	}                      
}

void solve() {          
	cin >> n;         
	cout << ans[n] << endl;
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