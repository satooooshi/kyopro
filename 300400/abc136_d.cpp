// doubling dp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int main() {
    string S;
    cin >> S;
    int N = S.size();

    // 初期値を埋める、 (2^0)先の遷移先
    vector<vector<int>> next(MAX, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'L') next[0][i] = i-1;
        else next[0][i] = i+1;
    }
    for (int d = 0; d+1 < MAX; ++d) { // further (2^0 is i's parent)
        for (int i = 0; i < N; ++i) { // every nodes
            // ex. node 1から出発して、2^3先の遷移node。
            // d+1==3 d==2 i==2
            //nv:=next[2][1]=3- > next[2][nv=3]
            next[d+1][i] = next[d][next[d][i]];
        }
    }

    vector<int> res(N, 0);
    int K = N*2;
    for (int v = 0; v < N; ++v) {
        int nv = v;
        // ex. node 10の13(01101)先の遷移先
        for (int d = 0; d < MAX; ++d) {
            // traverse from lsb
            // nv:=next[....1][10]
            // nv:=next[..1..][nv]
            // nv:=next[.1...][nv]
            if (K & (1<<d)) nv = next[d][nv];
        }
        res[nv]++;
    }
    for (int v = 0; v < N; ++v) cout << res[v] << " ";
    cout << endl;
}