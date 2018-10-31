// count the answer using the fact that numbers form arithmetic progression

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif	
    int tests;
    cin >> tests;
    while(tests--)
    {
        int x;
        cin >> x;
        x--;
        long long an = x - x % 3;
        long long na = an / 3;
        long long a1 = 3;
        long long bn = x - x % 5;
        long long nb = bn / 5;
        long long b1 = 5;
        long long sum = ((a1 + an) * na) / 2 + ((b1 + bn) * nb) / 2;
        long long cn = x - x % 15;
        long long nc = cn / 15;
        long long c1 = 15;
        if(x >= 15)
            sum -= (((c1 + cn) * nc) / 2);
        cout << sum << endl;
    }
    return 0;
}