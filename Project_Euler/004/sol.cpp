//  simple simulationw

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

int n;
int ans[MAXN];

void input() {

}

string f(int x) {
	string ans = "";
	while(x > 0) {
		ans += char('0' + x % 10);
		x /= 10;
	}
	reverse(all(ans));
	return ans;	
}

void go() {
	for(int i = 100; i < 1000; i++) 
		for(int j = i; j < 1000; j++) {
			int cur = i * j;
			if(cur >= MAXN) continue;
			string s = f(cur);
			string t = s;
			reverse(all(t));
			if(s == t) ans[cur + 1] = cur;	
		}
	for(int i = 100 * 100; i < MAXN; i++)
		if(ans[i + 1] == 0) ans[i + 1] = ans[i];	
}


void solve() {
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
	input();
	go();
	int t;
	cin >> t;
	while(t--) solve();
	TIMESTAMP;
	return 0;
}
