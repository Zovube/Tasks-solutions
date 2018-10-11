#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "homo"
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

bool used[MAXN];

void input() {
	int n;
	set < int > uniq;
	multiset < int > lst;
	cin >> n;
	bool homo = 0, hetero = 0;
	set < int > shomo;
	for(int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;
		if(s[0] == 'i') {
			uniq.insert(x);
			lst.insert(x);
			if(lst.count(x) > 1) {
				homo = 1;
				shomo.insert(x);
			}
		}
		else {
			if(uniq.count(x)) {
				lst.erase(lst.find(x));
				if(lst.count(x) == 0) uniq.erase(x);
				if(shomo.count(x) && lst.count(x) < 2) shomo.erase(x);
			}
		}
		if(sz(shomo)) homo = 1;
		else homo = 0;
		if(sz(uniq) > 1) hetero = 1;
		else hetero = 0;
		if(homo && hetero) cout << "both\n";
		else if(homo) cout << "homo\n";
		else if(hetero) cout << "hetero\n";
		else cout << "neither\n";
	}
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