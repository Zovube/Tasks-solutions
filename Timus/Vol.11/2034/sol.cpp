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

const int MAXN = 1e5 + 9;

int n, m;
vvi gg;
int dist[3][MAXN];
bool used[MAXN];

void input() {
    cin >> n >> m;
    gg.resize(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        gg[u].pb(v);
        gg[v].pb(u);
    }
}

void go(int start, int id) {
    memset(used, 0, sizeof(used));
    queue < int > qq;
    dist[id][start] = 0;
    qq.push(start);
    while(sz(qq)) {
        int v = qq.front();
        qq.pop();
        for(auto to : gg[v]) {
            if(!used[to]) {
                dist[id][to] = dist[id][v] + 1;
                used[to] = 1;
                qq.push(to);
            }
        }
    }
}

void solve() {
    int s, f, r; cin >> s >> f >> r;
    s--, f--, r--;
    go(s, 0);
    go(f, 1);
    go(r, 2);
    int ans = 0;
    assert(dist[0][f] == dist[1][s]);
    for(int i = 0; i < n; i++) {
        if(dist[0][i] + dist[1][i] == dist[0][f])
            ans = max(ans, dist[2][i]);
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