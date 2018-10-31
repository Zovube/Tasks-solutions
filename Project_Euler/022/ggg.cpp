// so easy with map

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
map < string, int > mp;

void input() {                  
	cin >> n;
	vs ss(n);
	for(int i = 0; i < n; i++) cin >> ss[i];
	sort(all(ss));
	for(int i = 0; i < n; i++) {
		int cur = 0;
		for(char x : ss[i]) cur += (x - 'A' + 1);
		mp[ss[i]] = cur * (i + 1);
	}
}

void solve() {          
	cin >> m;
	for(int i = 0; i < m; i++) {
		string s;
		cin >> s;
		cout << mp[s] << endl;
	}
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
