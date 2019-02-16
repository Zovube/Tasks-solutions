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

const int MAXN = 1444;

char aa[MAXN][MAXN];
int sum[MAXN][MAXN];
int n;
int win = -1;
int maxLen = 0;

void relaxAns(int cur) {
    // for(int i = 0; i < n; i++, cout << endl)
    //     for(int j = 0; j < n; j++)
    //         cout << sum[i][j] << ' ';
    // cout << endl;

    // for(int i = 0; i < n; i++, cout << endl)
    //     for(int j = 0; j < n; j++)
    //         cout << aa[i][j] << ' ';
    // cout << endl;

    int mx = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            mx = max(mx, sum[i][j]);
    debug(win, maxLen, cur, mx);
    if(mx > maxLen) {
        win = cur;
        maxLen = mx;
    }
    else if(mx == maxLen && win != cur && win != -1) {
        win = -1;
        maxLen = mx;
    }
    memset(sum, 0, sizeof(sum));
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            cin >> aa[i][j];
}

void solve() {
    // for(int i = n - 1; i >= 0; i--) {
    //     sum[i][n] = 0;
    //     for(int j = n - 1; j >= 0; j--) {
    //         if(aa[i][j] == 'S')
    //             sum[i][j] = sum[i][j + 1] + 1;
    //     } 
    // }
    // relaxAns(1);
    // for(int j = n - 1; j >= 0; j--) {
    //     sum[n][j] = 0;
    //     for(int i = n - 1; i >= 0; i--) {
    //         if(aa[i][j] == 'S')
    //             sum[i][j] = sum[i + 1][j] + 1;
    //     } 
    // }
    // relaxAns(1);
    // return;

    char c = 's';

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(aa[i][j] == c)
                sum[i][j] = sum[i][j + 1] + 1;
        } 
    }
    relaxAns(0);
    for(int j = n - 1; j >= 0; j--) {
        for(int i = n - 1; i >= 0; i--) {
            if(aa[i][j] == c)
                sum[i][j] = sum[i + 1][j] + 1;
        } 
    }
    relaxAns(0);

    for(int k = 0; k < n; k++) {
        int i = k, j = 0;
        for(int t = 0; t <= k; t++) {
            if(j > 0) {
                if(aa[i + 1][j - 1] == c && aa[i][j] == c)
                    sum[i][j] += sum[i + 1][j - 1];
            }
            if(aa[i][j] == c) sum[i][j]++;
            i--, j++;
        } 
    }
    relaxAns(0);
    for(int k = 1; k < n; k++) {
        int i = n - 1, j = k;
        for(int t = 0; t < (n - k); t++) {
            if(i < n + 1) {
                if(aa[i + 1][j - 1] == c && aa[i][j] == c)
                    sum[i][j] += sum[i + 1][j - 1];
            }
            if(aa[i][j] == c) sum[i][j]++;
            i--, j++;
        } 
    }
    relaxAns(0);

    for(int k = 0; k < n; k++) {
        int j = k, i = 0;
        for(int t = 0; t <= (n - k); t++) {
            if(i > 0) {
                if(aa[i - 1][j - 1] == c && aa[i][j] == c)
                    sum[i][j] += sum[i - 1][j - 1];
            }
            if(aa[i][j] == c) sum[i][j]++;
            i++, j++;
        } 
    }
    relaxAns(0);
    for(int k = 1; k < n; k++) {
        int i = k, j = 0;
        for(int t = 0; t < (n - k); t++) {
            if(i > 0) {
                if(aa[i - 1][j - 1] == c && aa[i][j] == c)
                    sum[i][j] += sum[i - 1][j - 1];
            }
            if(aa[i][j] == c) sum[i][j]++;
            i++, j++;
        } 
    }
    relaxAns(0);

    c = 'S';

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(aa[i][j] == c)
                sum[i][j] = sum[i][j + 1] + 1;
        } 
    }
    relaxAns(1);
    for(int j = n - 1; j >= 0; j--) {
        for(int i = n - 1; i >= 0; i--) {
            if(aa[i][j] == c)
                sum[i][j] = sum[i + 1][j] + 1;
        } 
    }
    relaxAns(1);

    for(int k = 0; k < n; k++) {
        int i = k, j = 0;
        for(int t = 0; t <= k; t++) {
            if(j > 0) {
                if(aa[i + 1][j - 1] == c && aa[i][j] == c)
                    sum[i][j] += sum[i + 1][j - 1];
            }
            if(aa[i][j] == c) sum[i][j]++;
            i--, j++;
        } 
    }
    relaxAns(1);
    for(int k = 1; k < n; k++) {
        int i = n - 1, j = k;
        for(int t = 0; t < (n - k); t++) {
            if(i < n + 1) {
                if(aa[i + 1][j - 1] == c && aa[i][j] == c)
                    sum[i][j] += sum[i + 1][j - 1];
            }
            if(aa[i][j] == c) sum[i][j]++;
            i--, j++;
        } 
    }
    relaxAns(1);

    for(int k = 0; k < n; k++) {
        int j = k, i = 0;
        for(int t = 0; t <= (n - k); t++) {
            if(i > 0) {
                if(aa[i - 1][j - 1] == c && aa[i][j] == c)
                    sum[i][j] += sum[i - 1][j - 1];
            }
            if(aa[i][j] == c) sum[i][j]++;
            i++, j++;
        } 
    }
    relaxAns(1);
    for(int k = 1; k < n; k++) {
        int i = k, j = 0;
        for(int t = 0; t < (n - k); t++) {
            if(i > 0) {
                if(aa[i - 1][j - 1] == c && aa[i][j] == c)
                    sum[i][j] += sum[i - 1][j - 1];
            }
            if(aa[i][j] == c) sum[i][j]++;
            i++, j++;
        } 
    }
    relaxAns(1);



    if(win == 0) cout << "s\n";
    if(win == 1) cout << "S\n";
    if(win == -1) cout << "?\n";
    cout << maxLen << endl;
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