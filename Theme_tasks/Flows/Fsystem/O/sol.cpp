#include<bits/stdc++.h>
using namespace std;

bool out[55][55];
int V = 1, E;
int vv1[55][55], vv2[55][55];
const int MAXN = 1e4, INF = 1e9;;
int head[MAXN], to[MAXN], head_tmp[MAXN], nxt[MAXN], cap[MAXN];
int qq[MAXN], qh, qt;
int n, m, S =  MAXN - 1, T = MAXN - 2;
int lvl[MAXN];

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
        while(add = dfs(S, INF)) {
            flow += add;
        }
    }
    return flow;
}

void build() {
    fill(head, head + MAXN, -1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int curi = i, curj = j;
            if(out[curi][curj] || vv1[curi][curj]) continue;
            while(curi <= n && curj <= m && !out[curi][curj]) {
                vv1[curi][curj] = V;
                curi++;
                curj++;
            }
            V++;
        }
    }
    int tt = V;
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            int curi = i, curj = j;
            if(out[curi][curj] || vv2[curi][curj]) continue;
            while(curi <= n && curj >= 1 && !out[curi][curj]) {
                vv2[curi][curj] = V;
                curi++;
                curj--;
            }
            V++;
        }
    }
    /*
    for(int i = 1; i <= n; i++, cout << endl)
        for(int j = 1; j <= m; j++) cout << vv1[i][j] << ' '; 
    cout << endl;
    for(int i = 1; i <= n; i++, cout << endl)
        for(int j = 1; j <= m; j++) cout << vv2[i][j] << ' ';
    */
    S = V++, T = V++;
    for(int i = 1; i < tt; i++) 
        addEdge(S, i);
    for(int i = tt; i < V - 2; i++)     
        addEdge(i, T);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(out[i][j]) continue;
            addEdge(vv1[i][j], vv2[i][j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bishops.in", "r", stdin);
    freopen("bishops.out", "w", stdout);
    cin >> n >> m;
    n = m = 50;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            //cin >> c;
            if(i % 2) out[i][j] = 1;
        }
    }
    
    build();
    cout << max_flow() << endl;
    return 0;
}
