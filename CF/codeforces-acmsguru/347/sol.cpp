#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector < string > aa(n);

    auto cmp = [&] (string a, string b) {
        string tmp1 = a + b;
        string tmp2 = b + a;
        for(int i = 0; i < tmp1.size(); i++)
            if(tmp1[i] < tmp2[i]) return 1;
            else if(tmp1[i] > tmp2[i]) return 0;
        return 0;
    };

    for(auto &x : aa) cin >> x;

    sort(aa.begin(), aa.end(), cmp);

    for(auto x : aa) cout << x;
    cout << endl;

    return 0;
}
