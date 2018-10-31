#include<bits/stdc++.h>
using namespace std;

bool graph[1000][1000];
vector < int > mt;
vector < bool > used;
int n, m, k;

bool dfs(int v) {
    used[v] = 1;
    for(int to = 0; to < m; to++) 
        if(graph[v][to]) {
            if(mt[to] == -1 || (!used[mt[to]] && dfs(mt[to]))) {
                mt[to] = v;
                return 1;
            }
        }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;

    for(int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[v][u] = 1;
    }

    mt.assign(m, -1);

    for(int i = 0; i < n; i++) {
        used.assign(n, 0);
        dfs(i);
    }

    int ans = 0;
    for(int i = 0; i < m; i++) 
        ans += (mt[i] != -1);

    cout << n + m - ans;

    return 0;
}
