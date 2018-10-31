#include<bits/stdc++.h>
using namespace std;

int main () {
    int S, N;
    cin >> S >> N;
    vector < int > aa(S);
    for(int i = 0; i < S; i++) {
        cin >> aa[i];
        aa[i]--;
    }
    int ans = 0, cur_ans = 0;
    for(int i = 0; i < S; i++) {
        cur_ans += aa[i];
        if(cur_ans < 0) cur_ans = 0;
        ans = max(ans, cur_ans);
    }
    if(ans > N) cout << "NO";
    else cout << "YES";
    return 0;
}
