// simple brute-force

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
const int MAXN = 1e5 + 9;

int aa[31][31];
int di[] = {1, 0, 1, -1};
int dj[] = {1, 1, 0, 1};

void input() {
	memset(aa, 0, sizeof(aa));
	for(int i = 0; i < 20; i++) 
		for(int j = 0; j < 20; j++) 
			cin >> aa[i][j];
}

void solve() {
	int ans = 0;
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++) 
			for(int k = 0; k < 4; k++) {
				if(i < 3 && k == 3) continue;
				int cur = 1;
				for(int t = 0; t < 4; t++) cur *= aa[i + t * di[k]][j + t * dj[k]];
				ans = max(ans, cur);
			}
	cout << ans << endl;
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
const int MAXN = 1e5 + 9;

int aa[31][31];
int di[] = {1, 0, 1, -1};
int dj[] = {1, 1, 0, 1};

void input() {
	memset(aa, 0, sizeof(aa));
	for(int i = 0; i < 20; i++) 
		for(int j = 0; j < 20; j++) 
			cin >> aa[i][j];
}

void solve() {
	int ans = 0;
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++) 
			for(int k = 0; k < 4; k++) {
				if(i < 3 && k == 3) continue;
				int cur = 1;
				for(int t = 0; t < 4; t++) cur *= aa[i + t * di[k]][j + t * dj[k]];
				ans = max(ans, cur);
			}
	cout << ans << endl;
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
