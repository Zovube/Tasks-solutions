#include<bits/stdc++.h>
using namespace std;

string matr[1001], new_matr[1001];

void rotate(int n) {
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            new_matr[i][j] = matr[n - j - 1][i];
    for(int i = 0; i < n; i++) 
        matr[i] = new_matr[i];
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> matr[i];
        new_matr[i] = matr[i];
    }

    set < char > st;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            st.insert(matr[i][j]);

    if(st.size() == 1) {
        cout << "Yes\n";
        return 0;
    }

    st.clear();

    for(int i = 0; i < n; i++) {
        st.insert(matr[0][i]);
        st.insert(matr[i][0]);
        st.insert(matr[n - 1][i]);
        st.insert(matr[i][n - 1]);
    }
        
    if(st.size() == 1) {
        cout << "No" << endl;
        exit(0);
    }

    bool ok = 0;
    for(int i = 0; i < 4; i++) {
        rotate(n);
        
        bool yes = 1;
        
        for(int i = 0; i < n && yes; i++) {
            bool one_zero = 0, zero_one = 0;
            for(int j = 0; j < n - 1; j++) {
                if(matr[i][j] == '0' && matr[i][j + 1] == '1')
                    zero_one = 1;
                if(matr[i][j] == '1' && matr[i][j + 1] == '0')
                    one_zero = 1;
            }

            if(one_zero && zero_one)
                yes = 0;
        }

        if(yes) {
            ok = 1;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}
