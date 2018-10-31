#include<bits/stdc++.h>
using namespace std;

vector < vector < int  > > graph;
int dist[2 * 11111];

void go(int start, int n) {
    fill(dist, dist + 2 * n, INT_MAX);
    dist[start] = dist[start + n] = 0;
    priority_queue < pair < int , int > > pr_q;
    pr_q.push({dist[start], start});
    pr_q.push({dist[start], start + n});
    while(!pr_q.empty()) {
        auto x = pr_q.top();
        pr_q.pop();
        int v = x.second, cur_d = -x.first;
        if(dist[v] < cur_d) continue;
        for(auto to : graph[v]) {
            int len = ((max(to, v) - min(to, v)) == n) && (min(to, v) != start);
            if(dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                pr_q.push({-dist[to], to});
            }   
        }
    }   
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph.resize(2 * n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u + n].push_back(v + n);
        graph[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        graph[i].push_back(i + n);
        graph[i + n].push_back(i);
    }
    int start, finish;
    cin >> start >> finish;
    start--, finish--;
    go(start, n);
    int ans = min(dist[finish], dist[finish + n]);
    cout << ans << endl;
    return 0;
}
