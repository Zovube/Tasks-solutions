// only first digits of number affect the result

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
const int MAXN = 1e3 + 9;

int aa[MAXN][50];
int n;

void input() {                  
	cin >> n;
	char c;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s; 
		for(int j = 0; j < 50; j++) {
			c = s[j];
			aa[i][j] = (int)(c - '0');
		}
	}
}

void solve() {          
	vi ans;
	int cur = 0;
	for(int j = 11; j >= 0; j--) { 
		for(int i = 0; i < n; i++) cur += aa[i][j];
		ans.pb(cur % 10);
		cur /= 10;		
	}
	while(cur) {
		ans.pb(cur % 10);
		cur /= 10;
	}
	reverse(all(ans));
	for(int i = 0; i < 10; i++) cout << ans[i];
}

int main() {     
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
