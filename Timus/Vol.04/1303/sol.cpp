#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	// assert(freopen("test.in", "r", stdin));
	// assert(freopen("test.out", "w", stdout));
	int m; cin >> m;
	vector < pair < int, int > > aa, ans;
	while(1) {
		int l, r; cin >> l >> r;
		if(l == 0 && r == 0) break;
		if(min(l, r) >= m || max(l, r) <= 0) {
			continue;
		}
		aa.push_back(make_pair(l, r));
	}
	sort(aa.begin(), aa.end());
	int curR = 0, curM = 0;
	bool was = 0;
	for(int i = 0; i < aa.size(); i++) {
		if(aa[i].first > curR) {
			curR = curM;
			was = 0;
		}
		if(aa[i].first <= curR && aa[i].second > curM) {
			if(was) ans.pop_back();
			ans.push_back(aa[i]);
			curM = aa[i].second;
			was = 1;
		}
		if(curM >= m) break;
	}
	if(curM < m) {
		cout << "No solution\n";
		exit(0);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto x : ans) cout << x.first << ' ' << x.second << endl;
	return 0;
}