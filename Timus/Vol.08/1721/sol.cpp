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

int mt[1111], rmt[1111];
vvi gg;
bool used[1111];
bool col[1111];

bool try_kuhn(int v) {
    used[v] = 1;
    for(auto to : gg[v]) 
        if(mt[to] == -1 || (mt[to] != -1 && !used[mt[to]] && try_kuhn(mt[to]))) {
            mt[to] = v;
            rmt[v] = to;
            return 1;
        }
    return 0;
}

vpii getMatch(int n) {
    memset(mt, -1, sizeof(mt));
    memset(rmt, -1, sizeof(rmt));
    while(1) {
        bool any = 0;
        memset(used, 0, sizeof(used));
        for(int i = 0; i < n; i++) 
            if(rmt[i] == -1 && col[i] == 0)
                any |= try_kuhn(i);
        if(!any) break;
    }
    vpii ans;
    for(int i = 0; i < n; i++) 
        if(rmt[i] != -1) 
            ans.pb({i, rmt[i]});
    return ans;
}

void dfs(int v, int color = 0) {
    used[v] = 1;
    col[v] = color;
    for(auto to : gg[v]) {
        if(!used[to]) {
            dfs(to, color ^ 1);
        }
        else {
            assert(col[to] != col[v]);
        }
    }
}

void input() {
    int n; cin >> n;
    map < int, string > mp;
    vi type(n);
    vi rank(n);
    for(int i = 0; i < n; i++) {
        string s, t; int x;
        cin >> s >> t >> x;
        mp[i] = s;
        if(t[0] == 'a') type[i] = 2;
        if(t[0] == 's') type[i] = 1;
        if(t[0] == 't') type[i] = 0;
        rank[i] = x;        
    }
    gg.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(type[i] == type[j] && type[i] != 2) continue;
            if(abs(rank[i] - rank[j]) != 2) continue;
            gg[i].pb(j);
            gg[j].pb(i);
        }
    }
    for(int i = 0; i < n; i++) 
        if(!used[i])
            dfs(i);
    // for(int i = 0; i < n; i++) {
    //     debug(i, rank[i], mp[i], col[i]);
    //     for(auto to : gg[i])
    //         debug(mp[to], col[to]);
    // }
    memset(used, 0, sizeof(used));
    vpii match = getMatch(n);
    cout << sz(match) << endl;
    for(auto x : match) {
        if(type[x.se] == 1 || type[x.fi] == 0) 
            swap(x.fi, x.se);
        cout << mp[x.fi] << ' ' << mp[x.se] << endl;
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