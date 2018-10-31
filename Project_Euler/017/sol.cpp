// hate such tasks

#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", 1.0*clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector<string> vs;

const int INF = 1e9;
const int MAXN = 1e5 + 9;
const int MOD = 1e9 + 7;
bool used[MAXN];
int n, m;
ll x;
string ans;
map < int, string > mp;

void precalc() {                  
	//mp[0] = " Zero";
	mp[1] = " One";
	mp[2] = " Two";
	mp[3] = " Three";
	mp[4] = " Four";
	mp[5] = " Five";
	mp[6] = " Six";
	mp[7] = " Seven";
	mp[8] = " Eight";
	mp[9] = " Nine";
	mp[10] = " Ten";
	mp[11] = " Eleven";
	mp[12] = " Twelve";
	mp[13] = " Thirteen";
	mp[14] = " Fourteen";
	mp[15] = " Fifteen";
	mp[16] = " Sixteen";
	mp[17] = " Seventeen";	
	mp[18] = " Eighteen";
	mp[19] = " Nineteen";
	mp[20] = " Twenty";
	mp[30] = " Thirty";
	mp[40] = " Forty";
	mp[50] = " Fifty";
	mp[60] = " Sixty";
	mp[70] = " Seventy";
	mp[80] = " Eighty";
	mp[90] = " Ninety";
}                


int cnt;


void go(int x) {
	if(x >= 100) {
		ans += mp[x / 100] + " Hundred";
		x %= 100;
		if(x > 0) cnt += 3;
	}
	if(x >= 20) {
		ans += mp[x - x % 10];
		x %= 10;
	}
	else {
		x %= 20;
	}
	ans += mp[x];
} 
                       
void solve() {
	cin >> x;          
	if(x == 0) {
		cout << "Zero" << endl;
		return;
	}
	ans = "";
	if(x >= 1e9) {
		go(x / int(1e9));
		ans += " Billion";
		x = x % (int)(1e9);
	}
	if(x >= 1e6) {
		go(x / int(1e6));
		ans += " Million";
		x = x % (int)(1e6);
	}
	if(x >= 1e3) {
		go(x / int(1e3));
		ans += " Thousand";
		x = x % (int)(1e3);
	}                 
	go(x);              
	ans.erase(0, 1);
	cout << ans << endl;
	for(int i = 0; i < sz(ans); i++) cnt += (ans[i] != ' ');
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif	
	precalc();     
	/*for(int i = 1; i <= 1000; i++) solve(i);
	cout << cnt << endl;*/
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
