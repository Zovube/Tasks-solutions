#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    multiset < int > mmin;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mmin.insert(x);
    }
    int cur = *mmin.begin();
    if(n == 1) {
        cout << 1 << endl << cur << endl;
        return 0;
    }
    mmin.erase(mmin.find(cur));
    vector < int > ans;
    int res = 0;
    while(!mmin.empty()) {
        auto pcur = mmin.upper_bound(s - cur);
        if(pcur == mmin.end()) {
            ans.push_back(cur);
            cur = *mmin.begin();
            mmin.erase(mmin.find(cur));
            ans.push_back(cur);
            if(!mmin.empty()) {
                cur = *mmin.begin();
                mmin.erase(mmin.find(cur));
            }
        }
        else {
            ans.push_back(cur);
            cur = *pcur;
            mmin.erase(mmin.find(cur));
        }
        if(mmin.empty()) {
            res++;
            ans.push_back(cur);
        }
        res++;
    }
    cout << res << endl;
    for(auto x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}
