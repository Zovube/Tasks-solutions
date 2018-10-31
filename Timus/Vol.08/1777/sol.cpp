#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    vector < int > stones;
    for(int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        stones.push_back(x);
    }   
    while(1) {
        sort(stones.begin(), stones.end());
        int x = LONG_LONG_MAX;
        for(int i = 1; i < stones.size(); i++) {
            x = min(x, stones[i] - stones[i - 1]);
            if(stones[i] == stones[i - 1]) {
                cout << stones.size() - 2 << endl;
                return 0;
            }   
        }
        stones.push_back(x);
    }
    return 0;
}
