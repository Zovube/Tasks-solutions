// simple simulation because fibanachi numbers growth is exponential

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long a = 1, b = 1, c = 2;
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        a = 1;
        b = 1;
        c = 2;
        long long sum = 0;
        cin >> n;
        while(c <= n)
        {
            if(! (c & 1)) sum += c;
            a = b;
            b = c;
            c = a + b;
        }
        cout << sum << endl;
    }
    return 0;
}
