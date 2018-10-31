// just eratosthene`s sieve

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long

using namespace std;

const int MAXN = 10 * 100500;

bool pr[MAXN];
vector <int> primes;

void go() {
    for(ll i = 2; i < MAXN; i++) 
        if(!pr[i])
            for(ll j = i * i; j < MAXN; j += i) 
                pr[j] = 1;
    for(int i = 2; i < MAXN; i++) 
        if(!pr[i])
            primes.push_back(i);
}


int main(){
    go();
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << primes[n - 1] << endl;
    }
    return 0;
}
