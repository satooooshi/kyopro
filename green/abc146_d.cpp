#include "bits/stdc++.h" 
typedef long long ll;
using namespace std;
using Graph = vector<vector<pair<int,int>>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N;
    M=N-1;
    vector<int>color(N); // color[i]:= color assigned to incoming i th edge
    int mx=-1;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back({b,i+1}); // incoming to node b, i(1-based) th edge
    }

    color[0]=0; // 1≤ci≤K, suppose color incoming edge to root0 is 0 
    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<pair<int,int>> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push({0,0}); // 0 を橙色頂点にする, i==0 parent has no incoming edge

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        auto v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        int c=1;
        for (auto nv : G[v.first]) {
            if(color[v.second]==c)c++; // parent's color
            color[nv.second]=c++;
            mx=max(color[nv.second],mx);
            if (dist[nv.first] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv.first] = dist[v.first] + 1;
            que.push(nv);
        }
    }

    cout<<mx<<endl;
    // output color has to be the same edge order as input 
    for(int i=1;i<N;i++)cout<<color[i]<<endl;
    return 0;
}