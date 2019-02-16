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

const int MAXN = 100500;

// // 0
// 1  // 1
// 2  // 1/2
// 3  // 3/4
// 4  // 5/8
// 5  // 11/16
// 6  // 21/32
// 7  // 43/64
// 8  // 85/128
// 9  // 171/256
// 10 // 341/512
// 11 // 2 * a_{i - 2} + a_{i - 1} / 2^n

void slow() {
    // write code here
    int n; cin >> n;
    vector < ld > aa(n);
    aa[0] = 0, aa[1] = 1;
    for(int i = 2; i < n; i++) {
        aa[i] = (aa[i - 1] + aa[i - 2]) / 2;
        cout << aa[i] << endl;
    }
}

void solve(ld n) {
    ld log2 = log(2.0);
    ld log10 = log(10.0);
    ld log6 = log(6.0);
    ld cur = n * log2;
    for(int i = 0; i <= MAXN; i++) {
        if(i * log10 > cur) {
            if(i % 2 == 0) {
                if(i * log10 > cur * 2) 
                    cout << i - 2 << endl;
                else 
                    cout << i - 1 << endl;
            }
            else 
                cout << i - 1 << endl;
            return;
        }
    }
}

int main() {
#ifdef LOCAL
    assert(freopen("test.in", "r", stdin));
    assert(freopen("test.out", "w", stdout));
    auto start_time = clock();
#else
    // ???
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(20);
    cerr.setf(ios::fixed | ios::showpoint);
    cerr.precision(4);

    // slow();
    // for(int i = 0; i < 15; i++) {
    //     cout << i << " : ";
    //     solve(i);
    // }

    int n; cin >> n;
    solve(n);

#ifdef LOCAL
    auto end_time = clock();
    cerr << "time: " << (end_time - start_time) * 1.0 / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}