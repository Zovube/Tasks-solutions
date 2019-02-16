#include<bits/stdc++.h>
using namespace std;

string to_string(string s) {
	return '"' + s + '"';
}

string to_string(const char * s) {
	return to_string(string(s));
}

template < typename A, typename B > 
string to_string(pair <A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template < typename A > 
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x: v) {
		if(!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

void debug_out() {
	cerr << endl;
}

template < typename Head, typename... Tail > 
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define two(a) (1LL << (a))
#define fi first
#define se second
#define has(mask, i) ((mask >> i) & 1)

using ll = long long;
using vi = vector < int >;
using vll = vector < ll >;
using vvi = vector < vector < int > >;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using ld = long double;

mt19937_64 rnd((unsigned long) chrono::high_resolution_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 9;

vi aa;
int n;
int dp[5555][5555];

int f(int l, int r) {
	int &ans = dp[l][r];
	if(ans != -1) return ans;
	if(l == 0 && r == sz(aa)) return 0;
	ans = INT_MAX;
	if(l > 0 && r < sz(aa) && aa[l - 1] == aa[r + 1]) 
		ans = min(ans, f(l - 1, r + 1) + 1);
	if(l > 0) ans = min(ans, f(l - 1, r) + 1);
	if(r < sz(aa)) ans = min(ans, f(l, r + 1) + 1);
	debug(l, r, ans);
	return ans;
}

void input() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(!sz(aa) || aa.back() != x)
			aa.pb(x);
	}
}

void solve() {
	int ans = INT_MAX;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < sz(aa); i++) {
		ans = min(ans, f(i, i));
		debug(ans);
	}
	cout << ans - 1 << endl;
}

int main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	auto start_time = clock();
#else 
	#define TASK "test"
	// freopen(TASK".in", "r", stdin);
	// freopen(TASK".out", "w", stdout);
#endif
	input();
	solve();

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
#endif

	return 0;
}
