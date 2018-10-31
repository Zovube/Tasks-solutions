// j * j = i was pain 

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
const int MAXN = 28124;
const int MOD = 1e9 + 7;
bool ok[MAXN];
int n, m;

void precalc() {                  
	vi aa;
	for(int i = 1; i < MAXN; i++) {
		int cur = -i;
		for(int j = 1; j * j <= i; j++) {
			if(i % j == 0) {
				cur += i / j + j;
				if(j * j  == i) cur -= j;
			}
		}
		if(cur > i) aa.pb(i);
   	}
   	for(int i = 0; i < sz(aa); i++) {
   		for(int j = 0; j < sz(aa); j++) {
   			if(aa[i] + aa[j] < MAXN) {
   				ok[aa[i] + aa[j]] = 1;
   			}
   		}
   	}
   	int ans = 0;
   	for(int i = 1; i < MAXN; i++) if(!ok[i]) ans += i;
   	//cout << ans << endl;
}

void solve() {          
	cin >> n;
	if(n > 28123 || ok[n]) cout << "YES" << endl;
	else cout << "NO" << endl;
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
	while(t--) solve();
	return 0;
}
