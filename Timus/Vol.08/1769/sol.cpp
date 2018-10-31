#include<bits/stdc++.h>
using namespace std;

const int MAXN = 6e6 + 9;

bool used[MAXN];

int main() {
    int cur[] = {0, 0, 0, 0, 0, 0};
    int p_10[] = {1, 0, 0, 0, 0, 0};
    for(int i = 1; i < 6; i++) p_10[i] = p_10[i - 1] * 10;
    string s, tmp = "";
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        tmp = "";
        for(int j = i; j < min(i + 6, (int)(s.size())); j++) {
            tmp += s[j];
            used[stoi(tmp.c_str())] = 1;
        }
    }
    for(int i = 1; i < MAXN; i++) {
        if(!used[i]) {
            cout << i << endl;
            return 0;
        }
    }
    assert(0);
    return 0;
}
