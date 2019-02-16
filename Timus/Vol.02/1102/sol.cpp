#include<bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	int pos = 0;
	while(pos < s.size()) {
		int posTmp = pos;
		if(pos + 2 < s.size() && s.substr(pos, 3) == "one") 
			pos += 3;
		else if(pos + 4 < s.size() && s.substr(pos, 5) == "puton") 
			pos += 5;
		else if(pos + 8 < s.size() && s.substr(pos, 9) == "outputone") 
			pos += 9;
		else if(pos + 7 < s.size() && s.substr(pos, 8) == "outputon") 
			pos += 8;
		else if(pos + 5 < s.size() && s.substr(pos, 6) == "output") 
			pos += 6;
		else if(pos + 2 < s.size() && s.substr(pos, 3) == "out") 
			pos += 3;
		else if(pos + 7 < s.size() && s.substr(pos, 8) == "inputone") 
			pos += 8;
		else if(pos + 6 < s.size() && s.substr(pos, 7) == "inputon") 
			pos += 7;
		else if(pos + 4 < s.size() && s.substr(pos, 5) == "input") 
			pos += 5;
		else if(pos + 1 < s.size() && s.substr(pos, 2) == "in") 
			pos += 2;
		if(pos == posTmp) 
			break;
	}
	if(pos == s.size()) cout << "YES";
	else cout << "NO";
	cout << endl;
}

int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T--)
		solve();
	return 0;
}