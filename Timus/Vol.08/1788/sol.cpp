#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector < int > girls(n), boys(m);
    for(int i = 0; i < n; i++) cin >> girls[i];
    for(int i = 0; i < m; i++) cin >> boys[i];
    sort(girls.begin(), girls.end());
    sort(boys.begin(), boys.end());
    int ans = INT_MAX;
    for(int i = 0; i <= min(n, m); i++) {
        int cur_ans = 0;
        for(int j = 0; j < n - i; j++) cur_ans += girls[j];
        for(int j = 0; j < m - i; j++) cur_ans += boys[j] * i;
        ans = min(ans, cur_ans);
    }
    cout << ans << endl;
    return 0;
}
