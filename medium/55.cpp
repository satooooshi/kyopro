// C - Cat Snuke and a Voyage normal dfs can not record shortest distance --> use dijkstra
/*
normal dfs can not record shortest distance --> use dijkstra
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; // zero based indexing
        b--;
        G[a].push_back({b});
        G[b].push_back({a});
    }
    vector<bool> seen(n, false);  // 既に見たことがある頂点か記録する
    stack<int> st;
    st.emplace(0);  // sから探索する
    seen[0] = true;
    while (st.size() != 0) {   // 深さ優先探索
        int state = st.top();  // 現在の状態
        st.pop();
        for (auto next : G[state]) {
            if (!seen[next]) {  // 未探索の時のみ行う
                seen[next] = true;
                st.emplace(next);  //次の状態をqueueへ格納
            }
        }
    }
    if (seen[n-1]) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
*/


// dijkstra C - Cat Snuke and a Voyage
#include <bits/stdc++.h>
using namespace std;
struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>; // dist, node
const long long INF = 1LL << 60;


// 最短距離の経路復元
/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &prev) {
    int N = G.size();
    dis.resize(N, INF);
    prev.resize(N, -1); // 初期化
    priority_queue<P, vector<P>, greater<P>> pq; 
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

/* get_path(prev, t)
    入力：dijkstra で得た prev, ゴール t
    出力： t への最短路のパス
*/
vector<int> get_path(const vector<int> &prev, int t) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}

int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    vector<long long> dis;
    vector<int> prev;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back({b,1});
        g[b].push_back({a,1});
    }
    dijkstra(g,0,dis,prev);
    if (dis[n-1]==2) { // 期便を2つ使うことで, 島Nに行けるか調べたい
        cout << "POSSIBLE" <<endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}