#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "alarm"
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

const int MAXN = 1e5 + 9;
const int MOD = (int)(1e9 + 7);
const int INF = 1e9;

map < int, int > mp;

void input() {
	int n; cin >> n;
	mp[0] = 6;
	mp[1] = 2;
	mp[2] = 5;
	mp[3] = 5;
	mp[4] = 4;
	mp[5] = 5;
	mp[6] = 6;
	mp[7] = 3;
	mp[8] = 7;
	mp[9] = 6;
	for(int h = 0; h < 24; h++)
		for(int m = 0; m < 60; m++) {
			int a = h / 10, b = h % 10;
			int cur = mp[a] + mp[b];
			a = m / 10, b = m % 10;
			cur += mp[a] + mp[b];
			//cout << h / 10 << h % 10 << ":" << m / 10 << m % 10 << "    " << cur << endl;
			if(cur == n) {
				cout << h / 10 << h % 10 << ":" << m / 10 << m % 10 << endl;
				return;
			}
		}
	cout << "Impossible" << endl;
}

void solve() {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif	
	input();
	solve();
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}