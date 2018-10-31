#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string old_s = s;
    int l = 0, r = s.size() - 1;
    bool fl = 0;
    int posl = -1, posr = -1;
    while(l < r) {
        if(s[l] != s[r]) {
            posl = l, posr = r;
            s[r] = s[l];
        }
        l++, r--;
    }
    for(int i = s.size() / 2; i < s.size(); i++) {
        if(old_s[i] > s[i]) {
            s[i] = s[i] + 1;
            s[s.size() - 1 - i] = s[i];
            //cout << i << ' ' << s.size() - i << endl;
            for(int j = s.size() - i; j < i; j++) s[j] = '0';
            break;
        }
    }
    cout << s << endl;
    return 0;
}
