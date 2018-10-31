#include<bits/stdc++.h>
using namespace std;

int INF = 1e9;
const int MAXN = 200 * 200 * 2 + 9;
int n, S, T, E, head[MAXN], head_tmp[MAXN], to[MAXN], from[MAXN], cap[MAXN], nxt[MAXN];
int qq[MAXN], qh, qt, used[MAXN], lvl[MAXN];

void addEdge(int a, int b, int c) {
    to[E] = b;
    nxt[E] = head[a];
    cap[E] = c;
    from[E] = a;
    head[a] = E++;
    to[E] = a;
    nxt[E] = head[b];
    cap[E] = 0;
    from[E] = b;
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
    if(!flow || v == T) return flow;
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

int max_flow() {
    int flow = 0, add;
    while(bfs()) {
        copy(head, head + MAXN, head_tmp);
        while(add = dfs(S, INF)) flow += add;
    }
    return flow;
}

void dfs_check(int v) {
    used[v] = 1;
    for(int id = head[v]; id != -1; id = nxt[id]) {
        if(id & 1 || !cap[id] || used[to[id]]) continue;
        dfs_check(to[id]);
    }
}

int main() {
#ifndef LOCAL
    freopen("mincut.in", "r", stdin);
    freopen("mincut.out", "w", stdout);
#endif
    cin >> n;
    S = 0, T = n - 1;
    fill(head, head + MAXN, -1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if(x) 
                addEdge(i, j, x);
        }
    cout << max_flow() << endl;
    dfs_check(S);
    vector < pair < int , int > > ans;
    for(int i = 0; i < E; i += 2) {
        if(used[from[i]] && !used[to[i]])
            ans.push_back({from[i] + 1, to[i] + 1});
    }
    cout << ans.size() << endl;
    for(auto x : ans) 
        cout << x.first << ' ' << x.second << endl;
    return 0;
}
