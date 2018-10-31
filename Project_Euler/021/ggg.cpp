// simple precalc

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
const int MAXN = 1e5 + 9;
const int MOD = 1e9 + 7;
bool used[MAXN];
int n, m;
int mp[MAXN];

void precalc() {                  
	for(int i = 1; i < MAXN; i++) {
		ll x = i;     
		ll cur = -i;
		for(int j = 1; j * j < x; j++) {
			if(x % j == 0) {
				cur += j;
				cur += x / j;
			}
		}
		if(cur < MAXN) mp[i] = cur;                
	}
}

void solve() {          
	cin >> n;         
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(mp[mp[i]] == i && mp[i] != i) {
			ans += i;
		}
	}
	cout << ans << endl;
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
	int tt;
	cin >> tt;
	precalc();
	while(tt--) solve();
	return 0;
}
