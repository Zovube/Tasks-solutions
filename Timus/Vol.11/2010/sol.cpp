#include<bits/stdc++.h>
using namespace std;

bool ok(int a, int b, int n) {
    return (a >= 1 && a <= n && b >= 1 && b <= n);
}

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int ans = 8;

    ans = 0;
    int dx[] = {-1, -1,  -1,  0,  0,  1,  1,  1};
    int dy[] = { 1,  0,  -1,  1, -1, -1,  0,  1};
    for(int i = 0; i < 8; i++) 
        ans += ok(a + dx[i], b + dy[i], n);
    cout << "King: " << ans << endl;

    ans = 0;
    int dx1[] = {-2, -2, -1, -1,  1,  1,  2,  2}; 
    int dy1[] = {-1,  1, -2,  2, -2,  2, -1,  1};
    for(int i = 0; i < 8; i++) 
        ans += ok(a + dx1[i], b + dy1[i], n);
    cout << "Knight: " << ans << endl;

    int ans1 = 0;
    ans1 += max(min(a - 1, b - 1), 0);
    ans1 += max(min(n - a, n - b), 0);
    ans1 += max(min(a - 1, n - b), 0);
    ans1 += max(min(n - a, b - 1), 0);
    cout << "Bishop: " << ans1 << endl;

    int ans2 = 2 * (n - 1);
    cout << "Rook: " << ans2 << endl;

    cout << "Queen: " << ans1 + ans2 << endl;

    return 0;
}
