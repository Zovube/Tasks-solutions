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

int n;
vvi gg, gg1;
bool ok[1111];
bool used[1111];

void dfs(int v) {
    debug(v);
    used[v] = 1;
    ok[v] = 1;
    for(auto to : gg[v]) 
        if(!used[to])
            dfs(to);
}

void dfs1(int v) {
    debug(v, gg1[v]);
    used[v] = 1;
    ok[v] = 1;
    for(auto to : gg1[v]) 
        if(!used[to])
            dfs1(to);
}

void solve() {
    cin >> n;
    gg.resize(n);
    gg1.resize(n);
    string s; 
    while(cin >> s) {
        if(s == "BLOOD") break;
        int a = stoi(s); 
        int b;
        cin >> b;
        a--, b--;
        gg[a].pb(b);
        gg1[b].pb(a);
    }
    for(int i = 0; i < n; i++) 
        debug(i, gg[i], gg1[i]);
    int a;
    while(cin >> a) {
        memset(used, 0, sizeof(used));
        debug(a - 1, 1);
        dfs(a - 1);
        memset(used, 0, sizeof(used));
        debug(a - 1, 2);
        dfs1(a - 1);
    }
    bool any = 0;
    for(int i = 0; i < n; i++) {
        if(!ok[i]) {
            cout << i + 1 << ' ';
            any = 1;
        }
    }
    if(!any) cout << any << endl;
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