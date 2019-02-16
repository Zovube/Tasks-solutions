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

vvi manacher(string s) {
    int n = sz(s);
    vvi p(2, vi(n, 0));
    for (int z = 0, l = 0, r = 0; z < 2; z++, l = 0, r = 0) {
        for (int i = 0; i < n; i++) {
            if (i < r) p[z][i] = min(r - i + !z, p[z][l + r - i + !z]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1]) p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    }
    return p;
}

void cry() {
	cout << "Impossible" << endl;
	exit(0);
}

void rot(string &s) {
	char tmp = s[0];
	for(int i = 0; i < sz(s) - 1; i++) 
		s[i] = s[i + 1];
	s[sz(s) - 1] = tmp;
}

bool isPal(const string &s) {
	int l = 0, r = sz(s) - 1;
	while(r > l) {
		if(s[l] != s[r]) return 0;
		l++, r--;
	}
	return 1;
}

void input() {
	string s; cin >> s;
	if(sz(s) & 1) {
		char x = s[0];
		bool difr = 0;
		for(int i = 0; i < sz(s); i++) 
			if(s[i] != x && i != sz(s) / 2) 
				difr = 1;
		if(!difr) cry();
	}
	bool un = 1;
	for(int i = 1; i < sz(s); i++) {
		if(s[i] != s[i - 1])
			un = 0;
	}
	if(un) 
		cry();
	string tmp = s;
	for(int i = 1; i < sz(s); i++) {
		rot(s);
		if(isPal(s) && s != tmp) {
			cout << 1 << endl;
			exit(0);
		}
	}
	cout << 2 << endl;
	// vvi man = manacher(s);
	// debug(man[0]);
	// debug(man[1]);
	// // return;

	// int len = sz(s);
	// int add = 2;
	// int ans = 0;
	// int used = 0;
	// while(1) {
	// 	debug(len);
	// 	bool was = 1;
	// 	if(len & 1) {
	// 		ans += add;
	// 		was = 0;
	// 		used++;
	// 	}
	// 	if(used >= 2) {
	// 		break;
	// 	}
	// 	add *= 2;
	// 	len /= 2;
	// 	if(len == 1) {
	// 		cry();
	// 	}
	// 	debug(add, len, ans);
	// 	if(len & 1) {
	// 		if(man[1][len / 2] != len / 2) {
	// 			ans += was;
	// 			break;
	// 		}			
	// 	}
	// 	else {
	// 		if(man[0][len / 2] != len / 2) {
	// 			ans += was;
	// 			break;
	// 		}						
	// 	}
	// }
	// int minAns = 6;
	// if(sz(s) % 2 == 0) minAns = 5;
	// cout << min(ans, minAns) << endl;
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
