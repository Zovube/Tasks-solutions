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

int cntG[MAXN], cntS[MAXN];
int n;
string s;

bool ok(int x) {
	for(int i = 0; i <= n - x; i++) {
		int cnt1 = cntG[i + x - 1];
		if(i) cnt1 -= cntG[i - 1];
		int cnt2 = cntS[i + x - 1];
		if(i) cnt2 -= cntS[i - 1];
		if(cnt2 == 0 || (cnt1 < cntG[n - 1] && cnt2 == 1 && cnt2 < cntS[n - 1]))
			return 1;
	}
	return 0;
}

void input() {
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'S') cntS[i] = 1;
		else cntG[i] = 1;
		if(i) {
			cntS[i] += cntS[i - 1];
			cntG[i] += cntG[i - 1];	
		}
	}
	debug(cntS[n - 1]);
	int l = 0, r = n + 1;
	while(r - l > 1) {
		int m = (l + r) / 2;
		debug(m, int(ok(m)));
		if(ok(m)) 
			l = m;
		else 
			r = m;
	}
	cout << l << endl;
}

void solve() {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
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
