#include<bits/stdc++.h>
using namespace std;

int main() {
    
    vector < int > cnt(1e6 + 9, 0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for(int i = 2; i <= 1e6; i++) {
        int curCnt = 0;
        for(int j = i; j <= 1e6; j += i)
            curCnt += cnt[j];
        if(curCnt >= 2)
            ans = max(ans, i);
    }

    cout << ans << endl;

    return 0;
}
