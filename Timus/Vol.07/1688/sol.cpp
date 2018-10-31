#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    int m;
    cin >> n >> m;
    n *= 3;
    long long sum = 0;
    for(int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        sum += x;
        if(sum > n) {
            cout << "Free after " << i + 1 << " times." << endl;
            return 0;
        }
    }
    cout << "Team.GOV!" << endl;
    return 0;
}
