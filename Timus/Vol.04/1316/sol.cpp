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

// structure for maintaining Fenwick Tree
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

struct Query {
    int type;
    int price;
    int amount;

    Query(int a, ld b, int c) : type(a), price(b), amount(c) {}
};

vector < Query > qq;

int to_i(string s) {
    int dist = -1;
    for(int i = 0; i < sz(s); i++)
        if(s[sz(s) - 1 - i] == '.')
            dist = i;
    if(dist == -1) {
        s += '.';
        s += '0';
        s += '0';        
    }
    if(dist == 0) {
        s += '0';
        s += '0';
    } 
    if(dist == 1) {
        s += '0';
    } 

    int ret = 0;
    for(int i = 0; i < sz(s); i++) {
        if(s[i] == '.') continue;
        ret = ret * 10 + int(s[i] - '0');
    }
    return ret;
}

void input() {
    string s;
    while(cin >> s) {
        if(s == "QUIT") break;
        if(s == "BID") {
            cin >> s;
            int x = to_i(s);
            qq.pb(Query(0, x, -1));
        }
        else if(s == "SALE") {
            int a; cin >> s >> a;
            int x = to_i(s);
            qq.pb(Query(1, x, a));            
        }
        else if(s == "DEL") {
            cin >> s;
            int x = to_i(s);
            qq.pb(Query(2, x, -1));            
        }
    }    
}

void solve() {
    vector < int > st;
    for(auto x : qq) 
        st.pb(x.price);
    sort(all(st));
    st.resize(unique(all(st)) - st.begin());
    bit.init(sz(st));
    ll ans = 0;
    for(auto x : qq) {
        if(x.type == 0) {
            int id = lower_bound(all(st), x.price) - st.begin();
            bit.add(id, 0, 1);
        }
        else if(x.type == 1) {
            int id = lower_bound(all(st), x.price) - st.begin();
            ans += min(x.amount * 1LL, bit.sum(id, sz(st) - 1));            
        }
        else {
            int id = lower_bound(all(st), x.price) - st.begin();
            bit.add(id, 0, -1);            
        }
    }
    cout << ans * 0.01 << endl;
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
    cout.precision(2);
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