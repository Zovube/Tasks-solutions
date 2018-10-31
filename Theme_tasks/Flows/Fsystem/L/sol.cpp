
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
#define TASK "domino"
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

int head[MAXN], head_tmp[MAXN], to[MAXN], cap[MAXN], nxt[MAXN], S, T, E;
int qq[MAXN], lvl[MAXN], qh, qt, N, M;

void addEdge(int a, int b) {
    to[E] = b;
    cap[E] = 1;
    nxt[E] = head[a];
    head[a] = E++;
    to[E] = a;
    cap[E] = 0;
    nxt[E] = head[b];
    head[b] = E++;
}

bool bfs() {
    fill(lvl, lvl + MAXN, INF);
    lvl[S] = 0;
    qh = qt = 0;
    qq[qt++] = S;
    while(qh != qt) {
        int v = qq[qh++];
        for(int id = head[v]; id != -1; id = nxt[id]) {
            if(!cap[id] || lvl[to[id]] <= lvl[v] + 1) continue;
            lvl[to[id]] = lvl[v] + 1;
            qq[qt++] = to[id];
        }
    }
    return lvl[T] != INF;
}


int dfs(int v, int flow) {
    if(!flow ||  v == T) return flow;
    for(int &id = head_tmp[v]; id != -1; id = nxt[id]) {
        if(!cap[id] || lvl[to[id]] != lvl[v] + 1) continue;
        int res = dfs(to[id], min(flow, cap[id]));
        if(res) {
            cap[id] -= res;
            cap[id ^ 1] += res;
            return res;
        }
    }
    return 0;
}

void solve() {

}


int max_flow() {
    int flow = 0, add;
    while(bfs()) {
        copy(head, head + MAXN, head_tmp);
        while(add = dfs(S, INF)) flow += add;
    }
    return flow;
}

int aa[44][44];

void input() {
    cin >> N;
    M = N;
    fill(head, head + MAXN, -1);
    S = N * M, T = S + 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> aa[i][j];
            if(!aa[i][j]) {
                if((i + j) % 2) {
                    addEdge(S, i * M + j);
                    if(i && !aa[i - 1][j]) addEdge(i * M + j, (i - 1) * M + j);
                    if(j && !aa[i][j - 1]) addEdge(i * M + j, i * M + j - 1);
                }
                else {
                    addEdge(i * M + j, T); 
                    if(i && !aa[i - 1][j]) addEdge((i - 1) * M + j, i * M + j);
                    if(j && !aa[i][j - 1]) addEdge(i * M + j - 1, i * M + j);
                }
             }
         }
    }
    cout << max_flow() << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	//freopen("xxx.in", "r", stdin);
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

