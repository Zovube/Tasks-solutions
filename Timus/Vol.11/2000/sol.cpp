#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[100500];
    for(int i = 0; i < n; i++)
        cin >> array[i];
    int pos1, pos2;
    cin >> pos1 >> pos2;
    pos1--, pos2--;
    bool flag = 0;
    if(pos1 > pos2) {
        swap(pos1, pos2);
        flag = 1;
    }
    if(pos1 == pos2) {
        int sum1 = 0, sum2 = 0;
        sum1 = accumulate(array, array + pos1 + 1, 0);
        sum2 = accumulate(array + pos1, array + n, 0);
        cout << max(sum1, sum2) << " " << accumulate(array, array + n, 0) - max(sum1, sum2) << endl;
    }
    else {
        int sum1 = 0, sum2 = 0, pos_mid = (pos1 + pos2) / 2 + flag * ((pos1 + pos2) % 2);
        sum1 = accumulate(array, array + pos_mid + !flag, 0);
        sum2 = accumulate(array + pos_mid + !flag, array + n, 0);
        if(flag) swap(sum1, sum2);
        cout << sum1 << " " << sum2 << endl;
    }
    return 0;
}
