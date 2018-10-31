#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 10;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    vector < int > ans(MAXN + 1, 0);
    for(int i = 2; i <= MAXN; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(i % j == 0) ans[i]++;
        }
    }   
    for(int i = K; i <= 1e4; i++) {
        if(ans[i] == N && ans[i - K] == M) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
