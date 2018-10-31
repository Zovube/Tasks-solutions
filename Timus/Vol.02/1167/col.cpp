#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector < int > cnt_white(n + 1, 0), cnt_black(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt_white[i] = (x == 0) + (i ? cnt_white[i - 1] : 0);
        cnt_black[i] = (x == 1) + (i ? cnt_black[i - 1] : 0);
        //cout << i << " : " << cnt_white[i] << ' ' << cnt_black[i] << endl;
    }
    int dp[555][555];
    int prv_i[555];
    for(int i = 0; i <= n; i++) 
        for(int j = 0; j <= k; j++) { 
            dp[i][j] = INT_MAX;
            prv_i[j] = -1;
        }
    dp[0][0] = 0;
    prv_i[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            for(int prev_i = i - 1; prev_i >= 0; prev_i--) {
                if(dp[prev_i][j - 1] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[prev_i][j - 1] + (cnt_white[i] - cnt_white[prev_i]) * (cnt_black[i] - cnt_black[prev_i]));
                }
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
