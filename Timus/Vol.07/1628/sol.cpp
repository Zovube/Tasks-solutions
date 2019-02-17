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

const int MAXN = 33333;
vi xx[MAXN], yy[MAXN];
int m, n, k;

void input() {
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        xx[a].pb(b);
        yy[b].pb(a);
    }
}

void solve() {
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        xx[i].pb(-1);
        xx[i].pb(n);
        sort(all(xx[i]));
    }
    for(int i = 0; i < n; i++) {
        yy[i].pb(-1);
        yy[i].pb(m);
        sort(all(yy[i]));
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < sz(xx[i]) - 1; j++) {
            if(xx[i][j + 1] - xx[i][j] > 2) ans++;
            if(xx[i][j + 1] - xx[i][j] == 2) {
                int l = *(lower_bound(all(yy[xx[i][j] + 1]), i) - 1);
                int r = *(lower_bound(all(yy[xx[i][j] + 1]), i));
                int concLen = r - l - 1;
                if(concLen <= 1) ans++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < sz(yy[i]) - 1; j++) {
            if(yy[i][j + 1] - yy[i][j] > 2) ans++;
            if(yy[i][j + 1] - yy[i][j] == 2) {
                int l = *(lower_bound(all(xx[yy[i][j] + 1]), i) - 1);
                int r = *(lower_bound(all(xx[yy[i][j] + 1]), i));
                int concLen = r - l - 1;
                if(concLen < 1) ans++;
            }
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