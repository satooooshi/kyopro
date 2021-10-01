// DP 更新順序が非自明なためにメモ化再帰が有効ßß
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long infll = 1LL<<60; // 62-bit long, MSBit is reserved for  pos/neg bit.


// 入力
int N, M;
vector<vector<int> > G; // グラフ

// メモ化再帰 DFS式topological sort
int dp[100100];
int rec(int v) {
    if (dp[v] != -1) return dp[v]; // 既に更新済み

    int res = 0;
    for (auto nv : G[v]) {
        chmax(res, rec(nv) + 1); 
    }
    return dp[v] = res; // メモしながらリターン, // 更新が完了する順を (逆順に) 辿ればそれが自然にトポロジカルソート順になっています。
}


int main() {
    // 入力受け取り
    cin >> N >> M;
    G.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        --x, --y; // 0-indexed にする
        G[x].push_back(y);
    }

    // 初期化
    for (int v = 0; v < N; ++v) dp[v] = -1;

    // 全ノードを一通り更新しながら答えを求める
    int res = 0;
    for (int v = 0; v < N; ++v) chmax(res, rec(v));
    cout << res << endl;
}


/*
BFS siki topological sort

// 入力
int N, M;
vector<vector<int> > G; // グラフ
vector<int> deg; // 各頂点の入次数

int dp[100100];
int main() {
    // 入力受け取り, 入次数も管理する
    cin >> N >> M;
    G.assign(N, vector<int>());
    deg.assign(N, 0);
    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        --x, --y; // 0-indexed にする
        G[x].push_back(y);
        deg[y]++;
    }

    // source をキューに突っ込む
    queue<int> que;
    for (int v = 0; v < N; ++v) if (deg[v] == 0) que.push(v);

    // BFS
    while (!que.empty()) {
        int v = que.front(); que.pop(); // que.pop()する順を辿ればそれが自然にトポロジカルソート順になっています。 
        for (auto nv : G[v]) {
            deg[nv]--; // エッジ (v, nv) を破壊する(parent he tuzuku edge wo hakai)
            if (deg[nv] == 0) {
                que.push(nv); // それによって入次数が 0 にあったならキューに突っ込む
                chmax(dp[nv], dp[v] + 1); // さらにソースから nv までの再長距離が確定する
            }
        }
    }

    // 答え
    int res = 0;
    for (int v = 0; v < N; ++v) chmax(res, dp[v]);
    cout << res << endl;
}
*/