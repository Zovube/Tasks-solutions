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
const int MAXN = 5e5 + 9;

vi cntL[MAXN];
vi cntR[MAXN];
bool used[MAXN];

pii getCnt(string s) {
	pii ret = {0, 0};
	for(auto x : s) {
		if(x == ')') {
			if(ret.se > 0) 
				ret.se--;
			else 
				ret.fi++;
		}
		else {
			ret.se++;			
		}
	} 
	debug(s, ret);
	return ret;
}

void input() {
	int n; cin >> n;
	int cntZero = 0;
	vector < string > aa(n);
	for(int i = 0; i < n; i++) {
		string x; cin >> x;
		aa[i] = x;
		pii curCnt = getCnt(x);
		if(curCnt.fi != 0 && curCnt.se != 0)
			continue;
		if(curCnt.fi > 0)
			cntL[curCnt.fi].pb(i);
		if(curCnt.se > 0)
			cntR[curCnt.se].pb(i);
		if(max(curCnt.fi, curCnt.se) == 0)
			cntZero++;
	}
	int ans = cntZero / 2;
	for(int i = 0; i < n; i++) {
		if(used[i])
			continue;
		string x = aa[i];
		pii curCnt = getCnt(x);
		if(curCnt.fi != 0 && curCnt.se != 0)
			continue;
		else if(max(curCnt.fi, curCnt.se) == 0)
			continue;


		if(curCnt.fi > 0) {
			if(sz(cntR[curCnt.fi])) {
				while(sz(cntR[curCnt.fi]) && used[cntR[curCnt.fi].back()])
					cntR[curCnt.fi].pop_back();
				if(!sz(cntR[curCnt.fi]))
					continue;
				int cur = cntR[curCnt.fi].back();
				used[cur] = 1;
				used[i] = 1;
				ans++;
			}
		}
		else if(curCnt.se > 0)
			if(sz(cntL[curCnt.se])) {
				while(sz(cntL[curCnt.se]) && used[cntL[curCnt.se].back()])
					cntL[curCnt.se].pop_back();
				if(!sz(cntL[curCnt.se]))
					continue;
				int cur = cntL[curCnt.se].back();
				used[cur] = 1;
				used[i] = 1;
				ans++;
			}
	}
	cout << ans << endl;
}

void solve() {

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
