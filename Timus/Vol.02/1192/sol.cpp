#include<bits/stdc++.h>
using namespace std;

int main() {
    long double a, V, K;
    cin >> V >> a >> K;
    if(a == 0 || a == 90) {
        cout << "0.00" << endl;
        return 0;
    }
    long double radians = a * 3.1415926535 / 180.;
    long double S = V * V * 2. * sin(radians) * cos(radians) / 10.0;
	cout << fixed << setprecision(2) << S / (1 - 1 / K) << endl;
	return 0; 
}
