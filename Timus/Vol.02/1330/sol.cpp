#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector < long long > ps(n, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i) 
            ps[i] = ps[i - 1];
        ps[i] += x;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        long long ans = ps[r];
        if(l) ans -= ps[l - 1];
        cout << ans << endl;
    }
    return 0;
}
