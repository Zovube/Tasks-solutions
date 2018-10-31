#include<bits/stdc++.h>
using namespace std;

int main() {
    set < pair < int, int > > sum_num;
    for(int i = 1; i < 1e5; i++) {
        int cur_s = 0, tmp = i;
        while(tmp) {
            cur_s += tmp % 10;
            tmp /= 10;
        }
        sum_num.insert({cur_s, i});
    }
    int sum;
    cin >> sum;
    vector < int > ans;
    while(sum) {
        auto x = sum_num.lower_bound(make_pair(sum, 100400));
        //assert(x != sum_num.end());
        if(x == sum_num.end() || x->first != sum) x--;
        cout << x->first << ' ' << x->second << endl;
        sum -= x->first;
        ans.push_back(x->second);
        sum_num.erase(x);
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << endl;
    return 0;
}
