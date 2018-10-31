#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cur = 2;
    vector < int > res;
    while(cur <= n) {
        res.push_back(cur / 2);
        cur *= 2;
    }
    if(2 * n != cur) res.push_back(n - cur / 2);
    cout << res.size() << endl;
    for(int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}
