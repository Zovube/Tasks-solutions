#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > graph;
int col[11111];

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[b].push_back(a);
    }
    bool ok = 1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        col[x] = 1;
        for(auto to : graph[x]) 
            if(!col[to]) {
                cout << "NO\n";
                return 0;
            }
    }
    cout << "YES\n";
    return 0;
}
