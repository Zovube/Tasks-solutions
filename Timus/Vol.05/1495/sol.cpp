#include<bits/stdc++.h>
using namespace std;

int mod;
map < int , char > dp[30];
map < int, int > pp[30];
int ten_pow[30], INF = 100500;

void rec(int len, int ost = 0) {
    cout << (int)dp[len][ost];
    if(len != 0) 
        rec(len - 1, pp[len][ost]);
}

int main() {
    cin >> mod;
    ten_pow[0] = 1;
    for(int i = 1; i < 30; i++) 
        ten_pow[i] = (ten_pow[i - 1] * 10) % mod;
    dp[0][(2 % mod)] = dp[0][(1 % mod)] = CHAR_MAX;
    dp[0][(2 % mod)] = min(dp[0][(2 % mod)], (char)2);
    dp[0][(1 % mod)] = min(dp[0][(1 % mod)], (char)1);
    int ok = 0;
    for(int len = 1; len < 30 && !ok; len++) {
        for(pair < int , char > cur : dp[len - 1]) {
            int ost = cur.first;
            if(dp[len - 1][ost] != INF) {
                int new_ost = (ost + (2 * ten_pow[len]) % mod) % mod;
                if(dp[len][new_ost] > (char)2 || dp[len][new_ost] == (char)0) {
                    dp[len][new_ost] = (char)2;
                    pp[len][new_ost] = ost;
                }
                if(new_ost == 0) {
                    ok = 1;
                }
                new_ost = (ost + (1 * ten_pow[len]) % mod) % mod;
                if(dp[len][new_ost] > (char)1 || dp[len][new_ost] == (char)0) {
                    dp[len][new_ost] = (char)1;
                    pp[len][new_ost] = ost;
                }
                if(new_ost == 0) {
                    ok = 1;
                    break;
                }
            }
        }
    }
    int start_len = -1;
    for(int i = 0; i < 30 && start_len == -1; i++) 
        if(dp[i][0] != (char)0) {
            start_len = i;
            break;
        }
    if(start_len == -1) {
        cout << "Impossible";
    }
    else {
        rec(start_len);
    }
    return 0;
}   
