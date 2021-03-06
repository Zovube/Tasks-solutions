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

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 9;

struct BIT {
	vll dataAdd;
	int size, mxlog;
	
	// initialize BIT and calculate mxlog for binsearch
	void init(int nn) {
		mxlog = 0;
		while((1 << mxlog) < nn) mxlog++; 
		size = (1 << mxlog) + 1;
		dataAdd.resize(size);
	}
	
	// add add to [pos]
	void add(int pos, ll add) {
		for(; pos < size; pos |= (pos + 1)) {
	 		dataAdd[pos] = (dataAdd[pos] + add) % MOD;
	 	}
	}
	
	// calculate sum on [0..pos]
	ll query(int pos) {
		ll add = 0;
	 	for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
	 		add = (add + dataAdd[pos]) % MOD;
	 	}
	 	return add;
	 }
	 
	 // calculate sum on [l..r]
	 ll sum(int l, int r) {
	 	ll val = query(r);
	 	ll sum = query(l - 1);
	 	return (val + MOD - sum) % MOD;
	 }
	 	 	 
} bit; 


void input() {

}

void solve() {
	string s; cin >> s;
	int n = sz(s);
	bit.init(n);
	int prev = -1;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'a') {
			if(prev == -1) 
				bit.add(i, 1);
			else {
				ll add = bit.sum(0, prev);
				add = (add + 1) % MOD;
				bit.add(i, add);
			}
		}
		else if(s[i] == 'b') {
			prev = i;
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		// debug(i, bit.sum(i, i));
		ans = (ans + bit.sum(i, i)) % MOD;
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
