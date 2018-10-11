#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "commuting"
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

const int MAXN = 2e5 + 9;
const int MOD = (int)(1e9 + 7);
const int INF = 1e9;

int gg[MAXN], rr[MAXN];
int n;
int ans[MAXN];
int T[MAXN];
int cnt = 0;
int tmp[MAXN], posTmp;

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void input() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x; 
		cin >> x;
		gg[i] = x;
		rr[x] = i;
	}
}

void go(int pos) {
	if(pos == n + 1) {
		cnt++;
		bool ok = 1;
		for(int i = 1; i <= n; i++) 	
			if(T[i] < ans[i]) 
				ok = 0;
			else if(ok && ans[i] < T[i]) {
				return;
			}
		for(int i = 1; i <= n; i++) {
			if(gg[T[i]] != T[gg[i]])
				return;
		}
		if(!ok) {
			cout << " found " << endl;
			cout << " input " << endl;
			for(int i = 1; i <= n; i++) 
				cout << gg[i] << ' ';
			cout << endl;
			cout << " ans " << endl;
			for(int i = 1; i <= n; i++) 
				cout << ans[i] << ' ';
			cout << endl;
			cout << " bettter ans " << endl;			
			for(int i = 1; i <= n; i++) 
				cout << T[i] << ' ';
			cout << endl;
			cout << " checking " << endl;
			for(int i = 1; i <= n; i++) 
				cout << gg[T[i]] - T[gg[i]] << ' ';
			cout << endl;

			exit(0);
		}
		return;
	}
	for(int i = 1; i <= n; i++) {
		T[pos] = i;
		go(pos + 1);
	}
}

void solve() {
	memset(ans, -1, sizeof(ans));
	vi cycles(n + 1, INF);	
	vi used(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		if(used[i]) continue;
		posTmp = 0;
		tmp[posTmp++] = gg[i];
		int v = gg[gg[i]];
		while(v != gg[i]) {
			used[v] = 1;
			tmp[posTmp++] = v;
			v = gg[v];
		}
		int curMin = *min_element(tmp, tmp + posTmp);
		cycles[posTmp] = min(cycles[posTmp], curMin);
	}
	
	for(int i = 1; i <= n; i++) {
		if(ans[i] != -1) continue;
		posTmp = 0;
		tmp[posTmp++] = gg[i];
		int v = gg[gg[i]];
		while(v != gg[i]) {
			tmp[posTmp++] = v;
			v = gg[v];
		}
		int cur = INF;
		cerr << i << ' ' << posTmp << endl;
		TIMESTAMP;
		for(int j = 1; j <= posTmp; j++) 
			if(posTmp % j == 0) 
				cur = min(cur, cycles[j]);
		for(int j = 0; j < posTmp; j++) {
			ans[rr[tmp[j]]] = cur;
			cur = gg[cur];
		}
	}
	for(int i = 1; i <= n; i++) 
		assert(ans[gg[i]] == gg[ans[i]]);
	//go(1);
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << endl;
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