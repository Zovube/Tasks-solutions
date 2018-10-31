// too easy

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
const ld eps = 1e-9;
bool used[MAXN];
int n, m;

ld type, sz;

void input() {                  
	cin >> type >> sz;
	if(type == 1) {
		sz *= 2;
	}
	if(type == 2) {
		sz *= sqrt(2);
	}                  
}

void solve() {          
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ld curtype, cursize;
		cin >> curtype >> cursize;
		if(curtype == 1) cursize *= 2;
		if(curtype == 3) cursize *= (sqrt(3) / 2);
		if(cursize - sz < eps) ans++;
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
	input();
	solve();
	return 0;
}
