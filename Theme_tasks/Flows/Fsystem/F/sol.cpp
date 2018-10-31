#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define dbg(x) cerr << #x << " == " << x << "\n";
#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "war"
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
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

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector <string> vs;
	
const int MAXN = 1e6 + 9;
const int MOD = (int)(1e9 + 7);
const int LOG2MAXN = 17;
const int INF = 1e9;
const ld eps = 1e-9;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int head[MAXN], head_tmp[MAXN], nxt[MAXN], cap[MAXN], cost[MAXN], to[MAXN], S, T, E;
int qq[MAXN], qh, qt, was[MAXN], N, M, pp[MAXN];
int dd[MAXN];

void addEdge(int a, int b, int c, int cc) {
    to[E] = b;
    cap[E] = c;
    cost[E] = cc;
    nxt[E] = head[a];
    head[a] = E++;
    to[E] = a;
    cap[E] = 0;
    cost[E] = -cc;
    nxt[E] = head[b];
    head[b] = E++; 
}

bool SPFA() {
    memset(was, 0, sizeof(was));
    qh = qt = 0;
    was[S] = 1;
    fill(dd, dd + MAXN, INF); 
    dd[S] = 0;
    qq[qt++] = S;
    while(qh != qt) {
        int v = qq[qh++];
        if(qh == MAXN) qh = 0;
        was[v] = 0;
        debug(qh, qt, v);
        for(int id = head[v]; id != -1; id = nxt[id]) {
            int nv = to[id];
            if(cap[id] > 0 && dd[nv] > dd[v] + cost[id]) {
                dd[nv] = dd[v] + cost[id];
                if(!was[nv]) {
                    was[nv] = 1;
                    qq[qt++] = nv;
                    if(qt == MAXN) qt = 0;
                }
                pp[nv] = id; 
            }
        }
    }
    return dd[T] != INF;
}

int mincost() {
    int cost_flow = 0, flow = 0;
    while(SPFA()) {
        int add = INF, add_cost = 0;
        for(int i = T; i != S; i = to[pp[i] ^ 1]) {
            add_cost += cost[pp[i]];
            add = min(add, cap[pp[i]]);
        }
        flow += add;
        cost_flow += add * add_cost;
        for(int i = T; i != S; i = to[pp[i] ^ 1]) {
            cap[pp[i]] -= add;
            cap[pp[i] ^ 1] += add;
        }
    }
    return cost_flow;
}

void solve() {
    fill(head, head + MAXN, -1);
    cin >> N >> M;
    S = N + M, T = S + 1;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        addEdge(S, i, x, 0);
    }
    for(int i = 0; i < M; i++) {
        int x; cin >> x;
        addEdge(N + i, T, x, 0);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int x; cin >> x;
            addEdge(i, N + j, INF, x);
        }
    }
    cout << mincost() << endl;
}

void input() {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#else
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	input();
	solve();
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}
