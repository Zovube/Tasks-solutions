#include<bits/stdc++.h>
using namespace std;

int main() {
	// assert(freopen("test.in", "r", stdin));
	// assert(freopen("test.out", "w", stdout));

	long long n; cin >> n;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		long long x; cin >> x;
		ans = __gcd(ans, x);
	}
	cout << ans << endl;
	return 0;
}