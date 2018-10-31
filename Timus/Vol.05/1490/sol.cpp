#include<bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    long double r;
    cin >> r;
    ans = (long long)(r) * 2 - 1;
    for(long long x = 1; x < (int)(r); x++) {
        long long sqr = (long long)r * (long long)r - (long long)x * (long long)x;
        long long msqrt = floor(sqrt(sqr));
        if(msqrt * msqrt == (long long)r * (long long)r - x * x) ans--;
        long long add = max(0, (int)(floor((sqrt(r * r - (long double)x * (long double)x)))));
        //cout << add << endl;
        ans += add;
    }
    cout << ans * 4 << endl;
}
