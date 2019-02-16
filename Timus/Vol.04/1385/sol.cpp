#include<bits/stdc++.h>
using namespace std;

int main() {
	// assert(freopen("test.in", "r", stdin));
	// assert(freopen("test.out", "w", stdout));
	int n; cin >> n;
	if(n == 1) {
		cout << 14 << endl;
	}
	else if(n == 2) {
		int ans = 0;
		for(int i = 1000; i < 10000; i++) {
			int a = i % 100;
			int b = i / 100;
			if(a != 0 && i % a == 0 && i % b == 0) ans++;
		}
		cout << ans << endl;
	}
	else {
		cout << "1575";
		for(int i = 0; i < n - 3; i++) 
			cout << '0';
		cout << endl;
	}
	return 0;
}