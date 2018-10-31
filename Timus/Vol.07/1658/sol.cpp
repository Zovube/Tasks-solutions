#include<bits/stdc++.h>
using namespace std;

int dp[901][8101];  // length of the minimal number
bool was[901][8101];
string ans;

int f(int s1, int s2) {
    if(min(s1, s2) < 0) return -1;
    if(was[s1][s2]) return dp[s1][s2];
    int res = 100500;
    for(int cur_num = 1; cur_num < 10; cur_num++) {
        int n_s1 = s1 - cur_num;
        int n_s2 = s2 - cur_num * cur_num;
        int n_res = f(n_s1, n_s2);
        if(n_res != -1 && n_res < 100) res = min(res, n_res + 1);
    }
    dp[s1][s2] = res;
    was[s1][s2] = 1;
    return res;
}

void find_ans(int s1, int s2) {
    for(int cur_num = 1; cur_num < 10; cur_num++) {
        if(cur_num <= s1 && s2 >= cur_num * cur_num && f(s1 - cur_num, s2 - cur_num * cur_num) == dp[s1][s2] - 1 && dp[s1 - cur_num][s2 - cur_num * cur_num] != -1) {
            ans += (char)(cur_num + '0');
            find_ans(s1 - cur_num, s2 - cur_num * cur_num);
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    was[0][0] = 1;
    for(int s1 = 1; s1 <= 900; s1++)
        for(int s2 = 1; s2 <= 8100; s2++)
            f(s1, s2);
    int tests;
    cin >> tests;
    while(tests--) {
        int s1, s2;
        cin >> s1 >> s2;
        ans = "";
        if(min(s1, s2) > 0 && s1 < 901 && s2 < 8101 && dp[s1][s2] != -1 && dp[s1][s2] < 101) {
            find_ans(s1, s2);
            sort(ans.begin(), ans.end());
            cout << ans << '\n';
        }
        else cout << "No solution\n";
    }
    return 0;
}
