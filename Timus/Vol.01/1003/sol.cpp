#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

map < int , vector < pair < int, int > > > gg;
map < int, int > col;

void addEdge(int a, int b, int c) {
    if(a > b) swap(a, b);
    a = a - 1, b = b + 1;
    gg[a].push_back({b, c});
    gg[b].push_back({a, c});
}

bool dfs(int v, int ccol = 1) {
    col[v] = ccol;
    for(auto to : gg[v]) {
        if(!col[to.fi] && !dfs(to.fi, (to.se ? 3 - ccol : ccol)))
            return 0;
        else if(col[to.fi] && (to.se && col[to.fi] == col[v] || !to.se && col[to.fi] != col[v]))
            return 0;
    }
    return 1;
}

bool check() {
    col.clear();
    for(auto v : gg) {
        if(!col[v.fi] && !dfs(v.fi)) 
            return 1;
    }
    return 0;
}

vector < pair < int, int > > aa;

bool ok(int m, int len) {
    gg.clear();
    for(int i = 0; i < m; i++) {
        bool h = (aa[i].first < 0);
        if(abs(aa[i].first) < 1 || abs(aa[i].second) > 2 * len)
            return 0;
        if(h) 
            addEdge(-aa[i].first, aa[i].second, 1);
        else 
            addEdge(aa[i].first, aa[i].second, 0);
    }
    if(check()) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x = 0;
    while(1) { 
        x++;
        int len; 
        cin >> len;
        if(len == -1) break;
        if(len == 0) {
            cout << 0 << endl;
            continue;
        }
        int n;
        cin >> n;
        aa.resize(0);
        for(int i = 0; i < n; i++) {
            int a, b;
            string s;
            cin >> a >> b >> s;
            a *= 2, b *= 2;
            if(s[0] == 'o') a *= -1;
            aa.push_back({a, b});
        }
        int l = 0, r = n + 2;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if(ok(m, len))
                l = m;
            else 
                r = m;
        }
        cout << l << endl;
    }
    return 0;
}
