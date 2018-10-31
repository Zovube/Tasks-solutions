#include<bits/stdc++.h>
#define prev ebanavrotebuchieplusi
using namespace std;


const int SQRT = 555;
const int MAXN = 1e5 + 9;
const int MOD = 1e9 + 7;

int deg[MAXN], ans[MAXN], lazy[MAXN], prev[MAXN];
vector < vector < int > > graph;

bool cmp(int a, int b) {
    return deg[a] > deg[b];
}

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
    if(a < 0)
        a += MOD;
}

int main() {
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ans[i];

    graph.resize(n);
    
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
        
        deg[a]++, deg[b]++;
    }

    for(int i = 0; i < n; i++) 
        sort(graph[i].begin(), graph[i].end(), cmp);

    cin >> m;
    for(int i = 0; i < m; i++) {
        int t, v;
        cin >> t >> v;
        v--;

        add(ans[v], MOD - prev[v]);
        prev[v] = 0;
        for(int j = 0; j < graph[v].size(); j++) {
            if(deg[j] <= SQRT) break;
            add(prev[v], lazy[j]);
            add(ans[v], lazy[j]);
        }   

        if(t == 1) {
            if(deg[v] <= SQRT) 
                for(auto to : graph[v]) 
                    add(ans[to], ans[v]);
            else {
                add(lazy[v], ans[v]);
            }
        }
        else {
            cout << ans[v] << endl;
        }
    }

    return 0;
}
