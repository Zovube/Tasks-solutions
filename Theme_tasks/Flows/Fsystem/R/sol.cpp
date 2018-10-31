#include<bits/stdc++.h>
using namespace std;

const int MAXV = 10333, MAXE = 4 * 2 * MAXV, INF = 1e9;

int head[MAXE], to[MAXE], nxt[MAXE], cap[MAXE], cost[MAXE], S, T, E;
int qq[MAXV], qh, qt;
int N, M, K;
int dd[MAXV], pp[MAXV], was[MAXV];
int aa[111][111];

void addEdge(int a, int b, int c, int cs) {
    to[E] = b;
    cap[E] = c;
    cost[E] = cs;
    nxt[E] = head[a];
    head[a] = E++;
    to[E] = a;
    cap[E] = 0;
    cost[E] = -cs;
    nxt[E] = head[b];
    head[b] = E++;
}

bool SPFA() {
    fill(dd, dd + MAXV, INF);
    fill(was, was + MAXV, 0);
    dd[S] = 0;
    was[S] = 1;
    qh = qt = 0;
    qq[qt++] = S;
    while(qh != qt) {
        int v = qq[qh++];
        was[v] = 0;
        if(qh == MAXV) qh = 0;
        for(int id = head[v]; id != -1; id = nxt[id]) {
            if(cap[id] <= 0) continue;
            int nv = to[id];
            if(dd[nv] > dd[v] + cost[id]) {
                pp[nv] = id;
                dd[nv] = dd[v] + cost[id];
                if(was[nv] == 0) {
                    qq[qt++] = nv;
                    if(qt == MAXV) qt = 0;
                    was[nv] = 1;
                }
            }
        }
    }
    return dd[T] != INF;
}

int mincost() {
    int flow = 0, flow_cost = 0;
    while(SPFA()) {
        int tmp_flow = INF, tmp_cost = 0;
        for(int v = T; v != S; v = to[pp[v] ^ 1]) {
           tmp_cost += cost[pp[v]];
           tmp_flow = min(cap[pp[v]], tmp_flow);
        }
        flow += tmp_flow;
        flow_cost += tmp_cost * tmp_flow;
        for(int v = T; v != S; v = to[pp[v] ^ 1]) {
            cap[pp[v]] -= tmp_flow;
            cap[pp[v] ^ 1] += tmp_flow;
        }
    }
    assert(flow == K);
    return flow_cost;
}

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator (seed);

int main() {
#ifndef LOCAL
    freopen("casino.in", "r", stdin);
    freopen("casino.out", "w", stdout);
#endif
        cin >> M >> N >> K;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                cin >> aa[i][j];
            }
        }
        fill(head, head + MAXV, -1);
        int tmp_s = 10000;
        S =10000 + 1, T = S + 1;
        swap(M, N);
        int TTT = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if((i + j) % 2) {
                    addEdge(tmp_s, i * M + j, 1, 0);
                    if(j < M - 1) addEdge(i * M + j, i * M + j + 1, 1, TTT - 1 * aa[i][j] * aa[i][j + 1]);
                    if(i < N - 1) addEdge(i * M + j, (i + 1) * M + j, 1, TTT - 1 * aa[i][j] * aa[i + 1][j]);
                    if(i > 0) addEdge(i * M + j, (i - 1) * M + j, 1, TTT - 1 * aa[i][j] * aa[i - 1][j]);
                    if(j > 0) addEdge(i * M + j, i * M + j - 1, 1, TTT - 1 * aa[i][j] * aa[i][j - 1]);
                }
                else {
                    addEdge(i * M + j, T, 1, 0);
                }  
            }
        }
        addEdge(S, tmp_s, K, 0);
        cout << K * TTT - 1 * mincost() << endl;
    return 0;
}
