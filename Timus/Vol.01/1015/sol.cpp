#include<bits/stdc++.h>
#define left fjdkfjkdfjk
#define right fdfdf
using namespace std;

vector < int >  cur(6), tmp(6);
int left = 0, right = 1, up = 2, down = 3, face = 4, back = 5;

map < vector < int >, int > type;

void rotate(int num) {
    tmp = cur;
    // left
    if(num == 0) {
        tmp[left] = cur[face];
        tmp[face] = cur[right];
        tmp[right] = cur[back];
        tmp[back] = cur[left];
    }
    // up
    if(num == 1) {
        tmp[up] = cur[face];
        tmp[face] = cur[down];
        tmp[down] = cur[back];
        tmp[back] = cur[up];
    }
    // down
    if(num == 2) {
        tmp[down] = cur[right];
        tmp[right] = cur[up];
        tmp[up] = cur[left];
        tmp[left] = cur[down];
    }
    cur = tmp;
}

void gen(int len, int lim, int cur_type) {
    if(type[cur] == 0) 
        type[cur] = cur_type;
    if(len == lim) 
        return;
    auto ttmp = cur;
    for(int i = 0; i < 3; i++) {
        rotate(i);
        gen(len + 1, lim, cur_type);
        cur = ttmp;
    }
}

void init() {
    for(int i = 0; i < 6; i++) 
        cur[i] = i + 1;
    int cur_type = 1;
    do {
        if(type[cur] != 0) continue;
        gen(0, 6, cur_type++);
    }
    while(next_permutation(cur.begin(), cur.end()));
}

int main() {
    init();
    int n;
    cin >> n;
    vector < int > types(n, 0);
    set < int > ans;
    for(int i = 0; i < n; i++) {
        cin >> cur[left] >> cur[right] >> cur[up] >> cur[face] >> cur[down] >> cur[back];
        types[i] = type[cur];
        ans.insert(types[i]);
    }
    cout << ans.size() << endl;
    vector < bool > used(n, 0);
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            int ct = types[i];
            for(int j = 0; j < n; j++) {
                if(types[j] == ct) {
                    cout << j + 1 << ' ';
                    used[j] = 1;    
                }
            }
            cout << endl;
        }
    }
    return 0;
}
