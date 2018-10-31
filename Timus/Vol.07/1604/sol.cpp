#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector < int > aa(n), pp(n);
    for(int i = 0; i < n; i++) {
        cin >> aa[i];
        pp[i] = i;
    }
    sort(pp.begin(), pp.end(), [&] (int i, int j) {
        return aa[i] > aa[j];
    });
    int num_max = 0;
    int num = aa[pp[0]];
    for(int i = n - 1; i >= 0 && aa[pp[i]]; i--) {
        for(int j = 0; j < aa[pp[n - i]]; j++) {
            if(aa[pp[num_max]] == 0) 
                num_max++;
            if(num_max == n - i - 1) cout << pp[i] << ' ';
            else {
                cout << pp[num_max] << ' ' << pp[i] << ' ';
                aa[pp[num_max]]--;
                if(aa[pp[num_max]] == 0) 
                    num_max++;
            }
        }
    }
    return 0;
}
    
