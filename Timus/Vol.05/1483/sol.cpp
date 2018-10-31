#include<bits/stdc++.h>
using namespace std;

int main() {
    int aa[3] = { 0, 0, 0 };
    for(int a = 0; a < 3; a++) {
        if(a == 0) aa[0]++, aa[1]++;
        if(a == 1) aa[0] += 3;
        if(a == 2) aa[1] += 3;
        for(int b = 0; b < 3; b++) {
            if(b == 0) aa[1]++, aa[2]++;
            if(b == 1) aa[1] += 3;
            if(b == 2) aa[2] += 3;
            for(int c = 0; c < 3; c++) {
                if(c == 0) aa[0]++, aa[2]++;
                if(c == 1) aa[0] += 3;
                if(c == 2) aa[2] += 3;
                vector < int > xx = { aa[0] , aa[1] , aa[2] };
                sort(xx.begin(), xx.end());
                for(auto x : xx) cout << x << ' ';
                cout << endl;
                if(c == 0) aa[0]--, aa[2]--;
                if(c == 1) aa[0] -= 3;
                if(c == 2) aa[2] -= 3;
            } 
            if(b == 0) aa[1]--, aa[2]--;
            if(b == 1) aa[1] -= 3;
            if(b == 2) aa[2] -= 3;
        }
        aa[0] = aa[1] = aa[2] = 0;
    }
    return 0;
}
