#include<bits/stdc++.h>
using namespace std;

int main() {
    int ans[100][100];
    memset(ans, -1, sizeof(ans));
    int n, k;
    cin >> n >> k;
    int cnt = (n + k - 1) / k;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < cnt && n--; j++) 
            cin >> ans[j][i];
    }
    for(int i = 0; i < cnt; i++, cout << endl)
        for(int j = 0; j < k; j++) 
           if(ans[i][j] != -1) 
                cout << setw(4) << ans[i][j];
    return 0;
}
