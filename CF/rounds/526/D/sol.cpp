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
const int MAXN = 3e5 + 9;

vector < vector < pair < ll, ll > > > gg; 
int n;
ll ww[MAXN];
ll dp[MAXN];
ll ans = 0;

void dfs(int v, int p = -1) {
	dp[v] = ww[v];
	vll best;
	for(auto x : gg[v]) {
		int to = x.fi;
		if(to == p) continue;
		dfs(to, v);
		best.pb(dp[to] - x.se);
	}

	sort(all(best));
	reverse(all(best));
	debug(v, best);
	if(!sz(best))
		return;
	dp[v] = max(dp[v], best[0] + ww[v]);

	if(sz(best) == 1) 
		return;
	ans = max(ans, best[0] + best[1] + ww[v]);
	debug(v, dp[v]);
}

void input() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> ww[i];
	gg.resize(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		gg[a].pb({b, c});
		swap(a, b);
		gg[a].pb({b, c});
	}
}

void solve() {
	dfs(0);
	for(int i = 0; i < n; i++) {
		debug(i, dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	assert(freopen("test.in", "r", stdin));
	assert(freopen("test.out", "w", stdout));
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