#include <bits/stdc++.h>
using namespace std;

string to_string(bool x) {
    return x ? "true" : "false";
}

string to_string(char x) {
    return string(1, x);
}

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string) s);
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
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

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define fi first
#define se second
#define two(a) (1LL << (a))
#define has(mask, i) ((mask >> i) & 1)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector < int >;
using vll = vector < ll >;
using vvi = vector < vector < int > >;
using vpii = vector < pii >;
using ld = long double;
using vs = vector < string >;

mt19937_64 rnd((unsigned long) chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAGIC = 1000;
const int MAXN = 1e5 + 9;
const int MAXM = 1e5;

vvi gg;
int n;
ll aa[MAXN], bb[MAXN];
ll ans[MAXN];

ll gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

void input() {
	gg.clear();
	cin >> n;
	gg.resize(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		gg[a].pb(b);
		gg[b].pb(a);
	}
	for(int i = 0; i < n; i++) cin >> aa[i];
	for(int i = 0; i < n; i++) cin >> bb[i];		
}

void dfs(int v, ll g = 0, int p = -1) {
	g = gcd(g, aa[v]);
	if(sz(gg[v]) != 1 || !v) {
		ans[v] = -1;
	}
	else {
		ans[v] = bb[v] - gcd(g, bb[v]);
	}
	for(auto to : gg[v]) {
		if(to != p) 
			dfs(to, g, v);
	}
}

void solve() {
	dfs(0);
	for(int i = 0; i < n; i++) 
		if(ans[i] != -1) 
			cout << ans[i] << ' ';
	cout << endl;
}

signed main() {
#ifdef LOCAL
    assert(freopen("test.in", "r", stdin));
    assert(freopen("test.out", "w", stdout));
    auto start_time = clock();
#else
    // string TASK = "";
    // assert(freopen(TASK".in", "r", stdin));
    // assert(freopen(TASK".out", "w", stdout));
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(12);
    cerr.setf(ios::fixed | ios::showpoint);
    cerr.precision(4);

    int tt; cin >> tt;
    while(tt--) {
        input();
        solve();
    }

#ifdef LOCAL
    auto end_time = clock();
    cerr << "time: " << (end_time - start_time) * 1.0 / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}