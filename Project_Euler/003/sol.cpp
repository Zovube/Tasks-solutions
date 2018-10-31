//  finding all factors in O(sqrt(n))

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        long long x = 2;
        long long ans = 0;
        while(x * x <= n)
        {
            if(n % x == 0)
            {
                while(n % x == 0) n /= x;
                ans = x;
            }
            x++;
        }
        cout << max(ans, n) << endl;
    }
    return 0;
}
