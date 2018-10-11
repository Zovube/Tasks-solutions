#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "image"
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

int dp[10][10][1 << 10];
int black[10][10];
pii nxt[10][10][1 << 10];
int w, h, n;

void input() {
	cin >> n >> w >> h;
	for(int t = 0; t < n; t++) {
		for(int i = 0; i < w; i++) 
			for(int j = 0; j < h; j++) {
				char c;
				cin >> c;
				if(c == 'W') 
					black[i][j] |= (1 << t);
			}		
	}
}

int go(int r, int c, int mask) {
	if(dp[r][c][mask] != -1) 
		return dp[r][c][mask];

	int &ret = dp[r][c][mask];	
	ret = INF;
	
	if(__builtin_popcount(mask) == 1) 
		return ret = 0;
	
	for(int i = 0; i < w; i++) {
		for(int j = 0; j < h; j++) {
			int mask1 = 0, mask2 = 0;
			mask1 = black[i][j] & mask;
			mask2 = mask - mask1;
			if(!mask1 || !mask2) continue;
			int cur = abs(c - j) + abs(r - i) + max(go(i, j, mask1), go(i, j, mask2));
			if(cur < ret) {
				ret = cur;
				nxt[r][c][mask] = {i, j};
			}
		}
	}
	return ret;
}

void out(int r, int c, int mask) {
	if((mask & (mask - 1)) == 0) {
		for(int i = 0; i < 10; i++) 
			if(mask == (1 << i)) {
				cout << i;
				return;
			}
	}
	pii to = nxt[r][c][mask];
	while(r > to.fi) {
		cout << "U";
		r--;
	}
	while(r < to.fi) {
		cout << "D";
		r++;
	}
	while(c < to.se) {
		cout << "R";
		c++;
	}
	while(c > to.se) {
		cout << "L";
		c--;
	}
	cout << "(";
	out(r, c, black[r][c] & mask);
	cout << ":";
	out(r, c, mask - (black[r][c] & mask));
	cout << ")";
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cerr << go(0, 0, (1 << n) - 1) << endl;
	cerr << "go OK" << endl;
	out(0, 0, (1 << n) - 1);
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