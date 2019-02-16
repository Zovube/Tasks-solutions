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

void input() {

}

const int MAXN = 1e4;

struct BIT {
    vll dataMul, dataAdd;
    int size, mxlog;
    
    // initialize BIT and calculate mxlog for binsearch
    void init(int nn) {
        mxlog = 0;
        while((1 << mxlog) < nn) mxlog++; 
        size = (1 << mxlog) + 1;
        dataMul.resize(size);
        dataAdd.resize(size);
    }
    
    // add linear function (mul * x + add) to [pos]
    void add(int pos, ll mul, ll add) {
        for(; pos < size; pos |= (pos + 1)) {
            dataMul[pos] += mul;
            dataAdd[pos] += add;
        }
    }
    
    // calculate sum on [0..pos]
    ll query(int pos) {
        ll mul = 0, add = 0, start = pos;
        for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            mul += dataMul[pos];
            add += dataAdd[pos];
        }
        return mul * start + add;
     }
     
     // add val to all elements on [l..r]
     void add_range(int l, int r, ll val) {
        add(l, val, (l - 1) * -val);
        add(r, -val, r * val);
     }
     
     // calculate sum on [l..r]
     ll sum(int l, int r) {
        return query(r) - query(l - 1);
     }
     
     // find k-th order statictic, almost binsearch
     int kth(ll k) {
        int res = 0;
        for(int i = mxlog; i >= 0; i--) {
            if(dataAdd[res + (1 << i) - 1] < k) {   
                k -= dataAdd[res + (1 << i) - 1];
                res += ((1 << i));
            }
        }
        return res; 
     }
         
} bit; 

int f(vi aa) {
    int ret = 0;
    for(int i = 0; i < sz(aa); i++) {
        ret += bit.sum(aa[i], MAXN);
        bit.add(aa[i], 0, 1);
    }
    for(int i = 0; i < sz(aa); i++) {
        bit.add(aa[i], 0, -1);
    }    
    debug(ret);
    return ret;
}

void solve() {
    int n, k; cin >> n >> k;
    bit.init(MAXN);
    int ans = -1, best = -1;
    for(int i = 0; i < k; i++) {
        vi aa(n);
        for(auto &x : aa) cin >> x;
        int cur = f(aa);
        if(cur > best) {
            best = cur;
            ans = i + 1;
        }
    }
    cout << ans << endl;
}

int main() {
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

    input();
    solve();

#ifdef LOCAL
    auto end_time = clock();
    cerr << "time: " << (end_time - start_time) * 1.0 / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}