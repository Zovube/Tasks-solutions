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

int aa[111][111];

void input() {

}

int get(int n) {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, aa[i][j] + aa[i - 1][j]);
            ans = max(ans, aa[i][j] + aa[i + 1][j]);
            ans = max(ans, aa[i][j] + aa[i][j - 1]);
            ans = max(ans, aa[i][j] + aa[i][j + 1]);            
        }
    }
    return ans;
}

void slow() {
    for(int n = 2; n < 4; n++) {
        vi ids(n * n);

        int ans = 100500;
        iota(all(ids), 1);
        debug(ids);
        do {
            int pos = 0;
            for(int i = 1; i <= n; i++) 
                for(int j = 1; j <= n; j++) 
                    aa[i][j] = ids[pos++];
            ans = min(ans, get(n));
        } while(next_permutation(all(ids)));

        cout << ans << endl;

        iota(all(ids), 1);
        do {
            int pos = 0;
            for(int i = 1; i <= n; i++) 
                for(int j = 1; j <= n; j++) 
                    aa[i][j] = ids[pos++];
            if(get(n) == ans) {
                for(int i = 1; i <= n; i++, cout << endl)
                    for(int j = 1; j <= n; j++)
                        cout << aa[i][j] << ' ';
                cout << "------------\n";
            }
        } while(next_permutation(all(ids)));
    }
}

bool check(int sum, int n) {
    // debug(sum, n);
    set < int > st;
    for(int i = 1; i < n * n; i++) 
        st.insert(i);
    aa[0][0] = n * n;
    bool ok = 1;
    for(int i = 0; ok && i < n; i++) {
        for(int j = 0; ok && j < n; j++) {
            if(i + j == 0) continue;
            int mx = 0;
            if(i > 0) mx = max(mx, aa[i - 1][j]);
            if(j > 0) mx = max(mx, aa[i][j - 1]);
            auto cur = st.lower_bound(sum - mx);
            if(cur == st.end()) cur--;
            if(*cur > sum - mx && cur == st.begin()) ok = 0;
            if(!ok) break;
            if(*cur > sum - mx) cur--;
            if(*cur > sum - mx) ok = 0;
            if(!ok) break;
            aa[i][j] = *cur;
            // debug(i, j, aa[i][j]);
            st.erase(st.find(*cur));
            // debug(st);
        }
    }
    return st.empty();
}

void solve() {
    int n; cin >> n;
    int mn = 100500;
    for(int sum = n * n + 26; sum >= 0; sum--) {
        bool ok = check(sum, n);
        if(ok) 
            mn = sum;
        else 
            break;
    }
    assert(check(mn, n));
    cout << mn << endl;
    for(int i = 0; i < n; i++, cout << endl)
        for(int j = 0; j < n; j++) 
            cout << aa[i][j] << ' ';
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