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

int m, n, s; 
vector < vpii > gg;
int col[111];
int dd[111];
int g[111][111];

bool dfs(int v, int p = -1) {
    debug(v);
    col[v] = 1;
    bool ok = 1;
    debug(gg[v]);
    for(auto x : gg[v]) {
        int to = x.fi;
        if(col[to] == 1 && to != p) ok &= 0;
        if(col[to] == 0) ok &= dfs(to, v);
        if(col[to] == 2) ok &= 1;
    }
    col[v] = 2;
    return ok;
}

void dfs1(int v) {
    col[v] = 1;
    for(auto x : gg[v]) {
        int to = x.fi;
        if(!col[to]) {
            dd[to] = dd[v] + x.se;
            dfs1(to);
        }
    }
}

void input() {
    cin >> n >> m >> s;
    gg.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        gg[a].pb({b, c});
        gg[b].pb({a, c});
        g[a][b]++;
        g[b][a]++;
        if(g[a][b] > 1) {
            cout << "YES" << endl;
            exit(0);
        }
    }
    bool ok = 1;
    debug(__LINE__);
    for(int i = 0; i < n; i++) {
        if(!col[i])
            ok &= dfs(i);
    }
    debug(__LINE__);
    if(!ok) cout << "YES" << endl;
    else {
        int mx = 0;
        for(int i = 0; i < n; i++) {
            memset(col, 0, sizeof(col));
            memset(dd, 0, sizeof(dd));
            dfs1(i);
            for(int j = 0; j < n; j++) 
                mx = max(mx, dd[j]);
        }
        if(mx >= s) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

void solve() {

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