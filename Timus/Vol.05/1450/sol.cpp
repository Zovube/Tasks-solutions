#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector < vector < pair < int, int > > > graph(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back({v, -w});
    }
    int s, f;
    cin >> s >> f;
	s--, f--;
    vector < int > dd(n, INT_MAX);
    dd[s] = 0;
    priority_queue < pair < int, int > > st;
    st.push({dd[s], s});
    while(!st.empty()) {
        int v = st.top().second;
		int cur_d = st.top().first;
        st.pop();
		if(cur_d > dd[v]) continue;
        for(auto x : graph[v]) {
            int to = x.first;
            int len = x.second;
            if(dd[to] > dd[v] + len) {
                dd[to] = dd[v] + len;
                st.push({dd[to], to});
            }
        }
    }
    if(dd[f] == INT_MAX) cout << "No solution";
	else cout << -dd[f];
	cout << endl;
    return 0;
}
