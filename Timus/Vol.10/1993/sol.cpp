#include<bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	string s; 
	getline(cin, s);
	int i = 0;
	{
		string t = "";
		for(i = 0; i < s.size(); i++) {
			if(s[i] == ',')
				break;
			t += s[i];
		}
		string a = "", b = "", c = "";
		for(int j = 0; j < t.size(); j++) {
			if(t[j] == '{') {
				j++;
				while(t[j] != '}') {
					a += t[j];
					j++;
				}
				assert(t[j] == '}');
			}
			if(t[j] == '(') {
				j++;
				while(t[j] != ')') {
					b += t[j];
					j++;
				}
				assert(t[j] == ')');
			}
			if(t[j] == '[') {
				j++;
				while(t[j] != ']') {
					c += t[j];
					j++;
				}
				assert(t[j] == ']');
			}
		}
		if(b[0] >= 'A' && b[0] <= 'Z') b[0] -= ('A' - 'a');
		if(c[0] >= 'A' && c[0] <= 'Z') c[0] -= ('A' - 'a');
		if(a[0] >= 'a' && a[0] <= 'z') a[0] -= ('a' - 'A');
		cout << a << ' ' << b << ' ' << c;
	}
	i++;
	if(i >= s.size()) return 0;
	{
		string t = "";
		for(i; i < s.size(); i++) {
			if(s[i] == ',')
				break;
			t += s[i];
		}
		string a = "", b = "", c = "", d = ""; 
		bool was = 0;
		for(int j = 0; j < t.size(); j++) {
			if(t[j] == '{') {
				j++;
				was = 1;
				while(t[j] != '}') {
					a += t[j];
					j++;
				}
				assert(t[j] == '}');
			}
			if(t[j] == '(') {
				j++;
				was = 1;
				while(t[j] != ')') {
					b += t[j];
					j++;
				}
				assert(t[j] == ')');
			}
			if(t[j] == '[') {
				j++;
				was = 1;
				while(t[j] != ']') {
					c += t[j];
					j++;
				}
				assert(t[j] == ']');
			}
			if(t[j] != ' ' && !was)
				d += t[j];
		}
		cout << ", " << d << ' ' << a << ' ' << b << ' ' << c;
	}
	return 0;
}