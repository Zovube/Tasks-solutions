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

struct point {
	ld x, y;
}

point aa[MAXN];

void input() {                  
	cin >> n;
	for(int i = 0; i < n; i++) cin >> aa[i].x >> aa[i].y;
}

ld ansx, ansy;

bool ok(ld r) {
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			
		}
	}
	return 0;
}	

void solve() {          
	ld l = 0, r = 10000;
	for(int i = 0; i < 100; i++) {
		ld m = (l + r ) / 2;
		if(ok(m)) r = m;
		else l = m;
	}
	ok(l);
	cout << ansx << ' ' << ansy << ' ' << setprecision(100) << l << endl;
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
