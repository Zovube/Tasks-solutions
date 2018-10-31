#include<bits/stdc++.h>
using namespace std;

bool ok(double x, double a, double b, double c) {\
    return x / a + x / b + x / c <= 1000.0;
}

int main() {
    long double a, b, c;
    cin >> a >> b >> c;
    double l = 0, r = 1e9;
    for(int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if(ok(m, a, b, c))
            l = m;
        else 
            r = m;
    }
    cout << round(l) << endl;
    return 0;
}
