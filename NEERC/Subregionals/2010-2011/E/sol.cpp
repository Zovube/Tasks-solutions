#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "explicit"
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

void input() {

}

void solve() {
	vi aa(10);
	for(int i = 0; i < 10; i++) cin >> aa[i];
	int ans = 0;
	for(int i = 0; i < 10; i++) {
		for(int j = i + 1; j < 10; j++) 
			ans ^= (aa[i] || aa[j]);
	}
	for(int i = 0; i < 10; i++) {
		for(int j = i + 1; j < 10; j++) 
			for(int k = j + 1; k < 10; k++) 
				ans ^= (aa[i] || aa[j] || aa[k]);
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