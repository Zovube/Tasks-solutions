}#include<bits/stdc++.h>
using namespace std;

const int MAXN = 30 * 200 * 200 + 9;
int firstx[MAXN], firstx_tmp[MAXN], nextx[MAXN], endx[MAXN], cap[MAXN];
int qq[MAXN], qt, qh;
map < pair < int, int > , bool > out, ok;
int n, m, E;
int col[MAXN];
int lvl[MAXN];
int S, F;
const int INF = 1e9;

void addEdge(int a, int b) {
    if(ok[make_pair(b, a)]) return;
    ok[make_pair(a, b)] = 1;
    endx[E] = b;
    nextx[E] = firstx[a];
    firstx[a] = E++;
    cap[E - 1] = 1;
    swap(a, b);
    endx[E] = b;
    nextx[E] = firstx[a];
    firstx[a] = E++;
    cap[E - 1] = 0;
}

void dfs1(int v, int ccol = 1) {
    col[v] = ccol;
    for(int id = firstx[v]; id != -1; id = nextx[id]) {
        int to = endx[id];
        if(col[to]) 
            assert(col[to] != col[v]);
        if(!col[to]) { 
            dfs1(to, 3 - ccol);
        }
    }
}

bool safe(int i, int j) {
    return i >= 1 && j >= 1 && i <= n && j <= n && !out[make_pair(i, j)];
}

void build() {
    fill(firstx, firstx + MAXN, -1);
    int di[] = {1, -1, 1, -1, 2, -2, 2, -2};
    int dj[] = {2, -2, -2, 2, 1, -1, -1, 1};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!safe(i, j)) continue;
            for(int k = 0; k < 8; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if(safe(ni, nj)) {
                    addEdge((i - 1) * n + j, (ni - 1) * n + nj);
                }
            }
        }
    }
    for(int i = 1; i <= n * n; i++) {
        if(!col[i] && !out[make_pair(i / n + (bool)(i % n), i % n + (i % n ? 0 : n))])
            dfs1(i);
        if(col[i] == 1) 
            addEdge(S, i);
        else 
            addEdge(i, F);
    }
}

bool bfs() {
    fill(lvl, lvl + MAXN, INF);
    lvl[S] = 0;
    qh = qt = 0;
    qq[qt++] = S;
    while(qh != qt) {
        int v = qq[qh++];
        for(int id = firstx[v]; id != -1; id = nextx[id]) {
           if(!cap[id] || lvl[endx[id]] <= lvl[v] + 1) continue;
           int to = endx[id];
           qq[qt++] = to;
           lvl[to] = lvl[v] + 1;
        }
    }
    return lvl[F] != INF;
}

int dfs(int v, int flow = INF) {
    if(v == F || flow == 0) return flow;
    for(int &id = firstx_tmp[v]; id != -1; id = nextx[id]) {
        int to = endx[id];
        if(!cap[id] || lvl[to] != lvl[v] + 1) continue;
        int res = dfs(to, min(flow, cap[id]));
        if(res) {
            cap[id] -= res;
            cap[id ^ 1] += res;
            return res;
        }
    }
    return 0;
}

int max_flow() {
    int flow = 0, add = 0;
    while(bfs()) {
        copy(firstx, firstx + MAXN, firstx_tmp);
        while(add = dfs(S)) {
            flow += add;
        }
    }
    cerr << flow << endl;
    return flow;
}
int main() {
    freopen("knights.in", "r", stdin);
    freopen("knights.out", "w", stdout);
    cin >> n >> m;
    S = n * n + 1, F = n * n + 2;   
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        cerr << a << ' ' << b << endl;
        out[make_pair(a, b)] = 1;
    }
    build();
    cout << n * n - max_flow() - m  << endl;
    return 0;
}
