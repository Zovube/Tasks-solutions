#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int tests;
    cin >> tests;
    while(tests--) {
        int n;
        cin >> n;
        int p, q;
        for(int i = 2; i * i < n; i++) {
            if(n % i == 0) {
                p = i, q = n / i;
                break;
            }
        }
        set < int > ans;
        cout << p << ' ' << q << endl;
        ans.insert((1 + 1 * p));
        ans.insert((0 + 1 * p));
        ans.insert((0 + 0 * p));
        ans.insert((1 + 0 * p));
        swap(p, q);
        ans.insert((1 + 1 * p));
        ans.insert((0 + 1 * p));
        ans.insert((0 + 0 * p));
        ans.insert((1 + 0 * p));
        for(auto x : ans) cout << x << ' ';
        cout << endl;
        ans.clear();
    }
    return 0;
}
