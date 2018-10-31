#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e4, INF = 1e9;
int gg[111][111], fl[111];
int n, m, S, T, E;
int head[MAXN], to[MAXN], cap[MAXN], nxt[MAXN], cost[MAXN];
int was[MAXN], dd[MAXN], pp[MAXN], qh, qt, qq[MAXN];

void addEdge(int a, int b, int cp, int cs) {
    to[E] = b;
    cap[E] = cp;
    cost[E] = cs;
    nxt[E] = head[a];
    head[a] = E++;
    to[E] = a;
    cap[E] = 0;
    cost[E] = -cs;
    nxt[E] = head[b];
    head[b] = E++;
}

bool SPFA() {
    fill(was, was + MAXN, 0);
    fill(dd, dd + MAXN, INF);
    was[S] = 1;
    dd[S] = 0;
    qh = qt = 0;
    qq[qt++] = S;
    while(qh != qt) {
        int v = qq[qh++];
        if(qh == MAXN) qh = 0;
        was[v] = 0;
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

pair < int, int > mincost() {
    int flow = 0, cost_flow = 0;
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
    return { flow, cost_flow };
}

int main() {
#ifndef LOCAL
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
#endif
    cin >> n >> m;
    S = n, T = n + 1;
    int sum = 0;
    fill(head, head + MAXN, -1);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int cur = b - a;
        sum += max(0, cur);
        if(cur > 0) 
            addEdge(S, i, cur, 0);
        else if(cur < 0)
            addEdge(i, T, -cur, 0);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            gg[i][j] = INF;
        gg[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        gg[a][b] = gg[b][a] = min(gg[a][b], c);
    }
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < i; j++) {
            if(gg[i][j]) {
                addEdge(i, j, INF, gg[i][j]);
                addEdge(j, i, INF, gg[i][j]);
            }
        }
    pair < int, int >  ans = mincost();
    if(ans.first == sum) 
        cout << ans.second << endl;
    else cout << -1;
    return 0;
}
