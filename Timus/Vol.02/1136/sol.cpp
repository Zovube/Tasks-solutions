#include<bits/stdc++.h>
using namespace std;

int aa[5555], left_child[5555], right_child[5555];

int n;

void go(int v, int l, int r) {
    if(l >= n || r >= n || l < 0 || r < 0) return;
    if(l > r) return;
    if(v < 0) return;
    int mid = -1;
    for(int i = r - 1; i >= l; i--) {
        if(i < 0) continue;
        if(aa[i] < aa[v] && aa[i + 1] > aa[v]) {
            mid = i;
            break;
        }
        if(aa[l] > aa[v]) break;
    }
    right_child[v] = r;
    left_child[v] = mid;
    if(mid >= 0) {
        go(mid, l, mid - 1);
        go(r, mid + 1, r - 1);
    }
    else 
        go(r, l, r - 1);
}

void out(int v) {
    if(right_child[v] >= 0) 
        out(right_child[v]);
    if(left_child[v] >= 0)
        out(left_child[v]);
    cout << aa[v] << endl;
}

int main() {
    memset(right_child, -1, sizeof(right_child));
    memset(left_child, -1, sizeof(left_child));
    cin >> n;
    if(!n) exit(0);
    for(int i = 0; i < n; i++) {
        cin >> aa[i];
    }
    go(n - 1, 0, n - 2);
    out(n - 1);
    return 0;
}
