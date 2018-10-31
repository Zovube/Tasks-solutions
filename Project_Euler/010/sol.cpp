// just sieve and precalc

#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define fi first
#define se second
#define pb push_back
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
typedef vector<string> vs;

const int INF = 100500;
const int MAXN = 1e6 + 9;

bool pr[MAXN];
ll ans[MAXN];

void sieve() {
	for(ll i = 2; i < MAXN; i++) 
		if(!pr[i]) 
			for(ll j = i * i; j < MAXN; j += i)
				pr[j] = 1;
	for(int i = 2; i < MAXN; i++) ans[i] = ans[i - 1] + (!pr[i] * i);  	
}

void input() {
	
}

void solve() {
	int n;
	cin >> n;
	cout << ans[n] << endl;
}

int main() {     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif	
	sieve();
	input();
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
