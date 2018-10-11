#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "grave"
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

bool inside(int x1, int y1, int x2, int y2, int nx, int ny) {
	return nx > x1 && nx < x2 && ny > y1 && ny < y2;
}

bool inside1(int x1, int y1, int x2, int y2, int nx, int ny) {
	return nx >= x1 && nx <= x2 && ny >= y1 && ny <= y2;
}

void input() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;
	int w, h; cin >> w >> h;
	if(w > x2 - x1 || h > y2 - y1) {
		cout << "No";
		return;
	}	

	{
		int nx = x1 + w, ny = y1 + h;
		bool ok = inside(x1, y1, nx, ny, x3, y3) || inside(x1, y1, nx, ny, x4, y4) || inside(x1, y1, nx, ny, x3, y4) || inside(x1, y1, nx, ny, x4, y3);
		//ok = 0;
		if(!ok && !inside(x3, y3, x4, y4, nx, ny) && inside1(x1, y1, x2, y2, nx, ny)) {
			cout << "Yes";
			return;
		}
	}
	{
		int nx = x1 + w, ny = y2 - h;
		bool ok = inside(x1, ny, nx, y2, x3, y3) || inside(x1, ny, nx, y2, x4, y4) || inside(x1, ny, nx, y2, x3, y4) || inside(x1, ny, nx, y2, x4, y3);
		//ok = 0;
		if(!ok && !inside(x3, y3, x4, y4, nx, ny) && inside1(x1, y1, x2, y2, nx, ny)) {
			cout << "Yes";
			return;
		}
	}
	{
		int nx = x2 - w, ny = y2 - h;
		bool ok = inside(nx, ny, x2, y2, x3, y3) || inside(nx, ny, x2, y2, x4, y4) || inside(nx, ny, x2, y2, x3, y4) || inside(nx, ny, x2, y2, x4, y3);
		//ok = 0;
		if(!ok && !inside(x3, y3, x4, y4, nx, ny) && inside1(x1, y1, x2, y2, nx, ny)) {
			cout << "Yes";
			return;
		}
	}
	{
		int nx = x2 - w, ny = y1 + h;
		bool ok = inside(nx, y1, x2, ny, x3, y3) || inside(nx, y1, x2, ny, x4, y4) || inside(nx, y1, x2, ny, x3, y4) || inside(nx, y1, x2, ny, x4, y3);
		//ok = 0;
		if(!ok && !inside(x3, y3, x4, y4, nx, ny) && inside1(x1, y1, x2, y2, nx, ny)) {
			cout << "Yes";
			return;
		}
	}
	cout << "No";
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