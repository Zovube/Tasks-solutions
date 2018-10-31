#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector < vector < string > > names(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            string x;
            cin >> x;
            names[i].push_back(x);
        }
        sort(names[i].begin(), names[i].end());
    }
    vector < string > ans;
    for(int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        cur--;
        for(int j = 0; j < 3; j++) {
            bool ok = 1;
            for(auto x : ans) 
                if(names[cur][j] < x) 
                    ok = 0;
            if(ok) {
                ans.push_back(names[cur][j]);
                //cout << cur << " : " << names[cur][j] << endl;
                break;
            }
        }
    }
    if(ans.size() != n) {
        cout << "IMPOSSIBLE";
    }
    else for(auto x : ans) cout << x << endl;
    cout << endl;
    return 0;
}   
