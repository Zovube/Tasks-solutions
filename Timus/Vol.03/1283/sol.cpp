#include<bits/stdc++.h>
using namespace std;

int main() {
    long double a, b, c;
    cin >> a >> b >> c;
    c = (1 - c / 100);
    //cout << b / a << ' ' << c << endl;
    long double ans = max((long double)0, log(b / a) / log(c));
    cout << ceil(ans) << endl;
    return 0;
}
