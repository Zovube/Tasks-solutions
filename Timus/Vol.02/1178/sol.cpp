#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector < pair < int, int > > dots;
    map < pair < int, int >, int > dot_num;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dot_num[{a, b}] = i + 1;
        dots.push_back({a, b});
    }
    sort(dots.begin(), dots.end());
    for(int i = 0; i < n; i += 2) {
        cout << dot_num[dots[i]] << ' ' << dot_num[dots[i + 1]] << endl;
    }
    return 0;
}
