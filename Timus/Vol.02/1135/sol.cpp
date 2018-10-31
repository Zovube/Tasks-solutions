#include<bits/stdc++.h>
using namespace std;

int main() {
    int cnt1 = 0, cnt0 = 0, ans = 0;
    int n;
    cin >> n;
    while(n--) {
        char c;
        cin >> c;
        if(c == '<') {
            cnt0++;
            ans += cnt1;
        }
        else {
            cnt1++;
        }
    }
    cout << ans << endl;
    return 0;
}
