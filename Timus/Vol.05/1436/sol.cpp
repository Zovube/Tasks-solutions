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

const ld INF = 1e9;

struct Point {
    ld x, y;
    Point(ld a, ld b) : x(a), y(b) {};
    ld dist(const Point &a) {
        return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
    }
};

struct Line {
    ld A, B, C;
    Line(const Point &p1, const Point &p2) {
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = -(A * p1.x + B * p1.y);
    }
    Point zero() {
        return Point(-C / A, 0);
    }
    bool onLineSeg(const Point &p1, const Point &p2, const Point &p3) {
        bool okX = (p1.x >= min(p2.x, p3.x) && p1.x <= max(p2.x, p3.x));
        bool okY = (p1.y >= min(p2.y, p3.y) && p1.y <= max(p2.y, p3.y));        
        return (A * p1.x + B * p1.y + C == 0) && okX && okY;
    }
};

ld f(Point p1, Point p2, Point p3) {
    ld a = p2.dist(p3);
    ld b = p1.dist(p2);
    ld c = p1.dist(p3);
    debug(a, b, c);
    ld alpha = acos((b * b + c * c - a * a) / (2 * b * c));
    if(alpha < 0)
        alpha += 2 * acos(-1.0);
    if(alpha > 2 * acos(-1.0))
        alpha -= 2 * acos(-1.0);
    return alpha;
}

void input() {
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1 = Point(x1, y1);
    Point p2 = Point(x2, y2);
    if(p1.y == p2.y) {
        cout << f(Point((p1.x + p2.x) / 2, 0), p1, p2) << endl;
        return;
    }
    Line l1 = Line(p1, p2);
    Point p3 = l1.zero();
    if(l1.onLine(p3, p1, p2)) {
        cout << acos(-1.0) << endl;
        return;
    }
    debug(p3.x, p3.y);
    ld l, r;
    ld ff = f(p3, p2, Point(p2.x, 0));
    debug(ff);
    ld ans1 = 0, ans2 = 0;
    {   
        l = p3.x, r = INF;
        debug(l, r);

        for(int i = 0; i < 100; i++) {
            ld l1 = (2 * l + r) / 3;
            ld r1 = (l + 2 * r) / 3;
            ld f1 = f(Point(0, l1), p1, p2);
            ld f2 = f(Point(0, r1), p1, p2);
            debug(f1, f2);
            if(f(Point(l1, 0), p1, p2) > f(Point(r1, 0), p1, p2)) 
                r = r1;
            else 
                l = l1;    
            debug(l, r);
        }
        debug(l);
        ans1 = f(Point(l, 0), p1, p2);
    }
    {   
        l = -INF, r = p3.x;
        debug(l, r);

        for(int i = 0; i < 100; i++) {
            ld l1 = (2 * l + r) / 3;
            ld r1 = (l + 2 * r) / 3;
            ld f1 = f(Point(0, l1), p1, p2);
            ld f2 = f(Point(0, r1), p1, p2);
            debug(f1, f2);
            if(f(Point(l1, 0), p1, p2) > f(Point(r1, 0), p1, p2)) 
                r = r1;
            else 
                l = l1;    
            debug(l, r);
        }
        debug(l);
        ans2 = f(Point(l, 0), p1, p2);
    }
    cout << max(ans1, ans2);
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