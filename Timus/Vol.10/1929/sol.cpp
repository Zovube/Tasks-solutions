#include<bits/stdc++.h>
using namespace std;

int ok[1111];

int main() {
	// assert(freopen("test.in", "r", stdin));
	// assert(freopen("test.out", "w", stdout));
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		ok[x - 1] = 1;
	}
	int ans = 0;
	for(int i = 1; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(ok[0] + ok[i] + ok[j] < 1)
				continue;
			int sum = m - ok[0] - ok[i] - ok[j];
			if(sum > 0 && sum * 3 >= (n - 3))
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}