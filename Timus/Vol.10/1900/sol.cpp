#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int n, k;
int sum[MAXN][MAXN];
int dp[MAXN][MAXN];
int pp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    //n = 500, k = n - 1;
    n--;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n - i; j++)
            //sum[i][j] = (i + j) % 41;
            cin >> sum[i][i + j];
    for(int i = 0; i < n; i++)
        for(int j = n - 1; j >= i; j--) {
            sum[i][j] += sum[i][j + 1];
            if(i) {
                sum[i][j] += sum[i - 1][j];
                sum[i][j] -= sum[i - 1][j + 1];
            }
        }
    /*
    for(int i = 0; i < n; i++, cout << endl) 
        for(int j = 0; j < n; j++) 
            cout << sum[i][j] << ' ';
    */
    for(int i = 0; i < n; i++) dp[i][0] = sum[i][i];
    for(int cur = 0; cur < n; cur++) {
        for(int num = 1; num < min(k, cur + 1); num++) {
            for(int pr = 0; pr < cur; pr++) {
                int cur_profit = sum[cur][cur] - sum[pr][cur];
                if(dp[cur][num] < dp[pr][num - 1] + cur_profit) {
                    dp[cur][num] = dp[pr][num - 1] + cur_profit;
                    pp[cur][num] = pr;
                }
            }
        }
    }
    int ans = 0, st = -1;
    for(int i = 0; i < n; i++) {
        if(ans < dp[i][k - 1]) {
            ans = dp[i][k - 1];
            st = i;
        }
    }
    cout << ans << endl;
    if(ans == 0) {
        for(int i = 0; i < k; i++) cout << i + 1 << ' ';
        cout << endl;
        return 0;
    }
    for(int i = k - 1; i >= 0; i--) {
        cout << st + 1 << ' ';
        st = pp[st][i];
    }
    cout << endl;
    return 0;
}



/* 
    5 0 6 
      5 3 
        5

    6 1
    5 0 6 1 2 
      5 3 3 5 
        5 9 8 
          0 0 
            1 
              

    

*/
