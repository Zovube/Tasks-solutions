#include<bits/stdc++.h>
using namespace std;

int my_queue[1111111];
int qh, qt, q_cnt, q_size = 1e6 + 100;;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == -1) {
            qh--;
            if(qh < 0) qh += q_size;
            cout << my_queue[qh] << endl;
            q_cnt--;
        }
        else if(x == 0) {
            if(q_cnt >= n - i - 1) continue;
            int tmp = qh - 1;
            if(tmp < 0) tmp += q_size;
            int lim = q_cnt;
            while(lim && q_cnt < n - i + 1) {
                qt--;
                if(qt < 0) qt += q_size;
                my_queue[qt] = my_queue[tmp];
                tmp--;
                if(tmp < 0) tmp += q_size;
                q_cnt++;
                lim--;
            }
        }
        else {
            my_queue[qh] = x;
            qh++;
            if(qh == q_size) qh = 0;
            q_cnt++;
        }
    }
    return 0;
}
