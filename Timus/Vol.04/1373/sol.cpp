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
using ld = double;
using vs = vector < string >;

mt19937_64 rnd((unsigned long) chrono::high_resolution_clock::now().time_since_epoch().count());

ld INF = 1e9;

struct Vector {
    ld x, y;
    Vector(ld a, ld b): x(a), y(b) {}
    Vector operator+ (const Vector &p) {
        return Vector(x + p.x, y + p.y);
    }
    Vector operator- (const Vector &p) {
        return Vector(x - p.x, y - p.y);
    }
    Vector operator/ (ld l) {
        return Vector(x / l, y / l);
    }
    Vector operator* (ld l) {
        return Vector(x * l, y * l);
    }
    Vector ortogonal1 () {
        return Vector(-y, x);
    }
    Vector ortogonal2 () {
        return Vector(y, -x);
    }
    ld len() {
        return sqrt(x * x + y * y);
    }
    void norm() {
        ld l = sqrt(x * x + y * y);
        x /= l, y /= l;
    }
};

ld mxx = -INF, mnx = INF, mxy = -INF, mny = INF;

void relax(Vector p) {
    mxx = max(mxx, p.x);
    mnx = min(mnx, p.x);
    mxy = max(mxy, p.y);
    mny = min(mny, p.y);
}

bool clockWise(Vector p1, Vector p2, Vector p3) {
    ld area = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return area < 0;
}

void input() {

}

void solve() {
    int a, b; 

    while(cin >> a >> b) {
        Vector p1 = Vector(a, b);
        cin >> a >> b;
        Vector p3 = Vector(a, b);
        Vector dir = p3 - p1;
        ld halfL = dir.len() / 2;
        Vector mid = (p1 + p3) / 2;
        {
            Vector ort = dir.ortogonal1();
            ort.norm();
            ort = ort * halfL;
            Vector p2 = mid + ort;
            if(clockWise(p1, p2, p3)) 
                relax(p2);
        }
        {
            Vector ort = dir.ortogonal2();
            ort.norm();
            ort = ort * halfL;
            Vector p2 = mid + ort;
            if(clockWise(p1, p2, p3)) 
                relax(p2);
        }
        relax(p1);
        relax(p3);
    }
    cout << max(ld(0), mxx - mnx) << ' ' << max(ld(0), mxy - mny) << endl;
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

    // for(int i = 0; i < 1e5; i++) 
    //     cout << "0 0 1 1" << endl;
    // return 0;
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