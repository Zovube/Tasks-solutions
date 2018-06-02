#include<bits/stdc++.h>
using namespace std;

vector < int > to_block;
vector < int > dist;
vector < bool > used;
vector < bool > in;

void dfs(int v, int d = 0) {
	used[v] = 1;
	dist[v] = d;
	if(to_block[v] != -1 && !used[to_block[v]]) 
		dfs(to_block[v], d + 1);
}

int main() {
	freopen("bureau.in", "r", stdin);
	freopen("bureau.out", "w", stdout);
	int n;
	cin >> n;
	
	to_block.resize(n, -1);
	dist.resize(n, 0);
	used.resize(n, 0);
	in.resize(n, 0);
	
	for(int i = 0; i < n; i++) {
		string s;
		int num;
		cin >> s;
		if(s[0] == 'd') continue;
		cin >> num;
		to_block[i] = num - 1;
		in[num - 1] = 1;
	}
	
	for(int i = 0; i < n; i++) {
		if(i == 98)
			cerr << in[i] << ' ' << used[i] << ' ' << to_block[i] << ' ' << dist[0] << endl;
		if(!in[i] && !used[i])
			dfs(i);
	}
	cerr << dist[98] << ' ' << dist[0] << endl;
	
	vector < int > ans;
	for(int i = 0; i < n; i++) 
		if(dist[i] % 2 == 0)
			ans.push_back(i);
			
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) 
		cout << ans[i] + 1 << ' ';
	
	return 0;
}