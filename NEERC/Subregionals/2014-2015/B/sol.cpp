#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "buffcraft"
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
	ll b, k, n, m;
	cin >> b >> k >> n >> m;
	
	vector < pair < ll, int > > aa(n);
	for(int i = 0; i < n; i++) {
		cin >> aa[i].fi;
		aa[i].se = i + 1;
	}
	
	vector < pair < ll, int > > bb(m);
	for(int i = 0; i < m; i++) {
		cin >> bb[i].fi;
		bb[i].se = i + 1;
	} 
	
	sort(all(aa)), sort(all(bb));
	reverse(all(aa)), reverse(all(bb));
	
	ll ans = 0, curA = b, curB = 100LL;
	for(int i = 0; i < min(k, n); i++) curA += aa[i].fi;
	
	int curCnt = min(k, n);
	ans = curA * curB;
	
	int allCnt = curCnt;
	int cnt1 = curCnt, cnt2 = 0;
	
	for(int i = 0; i < min(k, m); i++) {
		allCnt++;
		if(curCnt && allCnt > k) {
			curCnt--;
			curA -= aa[curCnt].fi;
			allCnt--;
		}
		
		//cerr << i << ' ' << curCnt << ' ' << allCnt << endl;
		curB += bb[i].fi;
		//cerr << curA * curB << endl;
		if(curA * curB > ans) {
			ans = max(ans, curA * curB);
			cnt1 = curCnt;
			cnt2 = i + 1;
		}
	}
	
	cout << cnt1 << ' ' << cnt2 << endl;
	
	for(int i = 0; i < cnt1; i++) cout << aa[i].se << ' ';
	cout << endl;
	
	for(int i = 0; i < cnt2; i++) cout << bb[i].se << ' ';
	cout << endl;

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