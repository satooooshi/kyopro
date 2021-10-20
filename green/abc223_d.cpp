#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;
/* topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号
    計算量: O(|E|+|V|)
 */
vector<int> topo_sort(const Graph &G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e.to]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) { // IMPORTANT!! can sort by asc using priority queue!!
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        int now = que.top();
        que.pop();
        ans.push_back(now);
        for (auto e : G[now]) {
            ind[e.to]--;
            if (ind[e.to] == 0) {
                que.push(e.to); // IMPORTANT!! can sort the node numbers by asc using priority queue!!
            }
        }
    }
    return ans;
}

int main() {
    int n,m;cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
            int a,b;cin>>a>>b;
            a--;
            b--;
            g[a].push_back({b});
    }
    auto v = topo_sort(g);
    if (v.size() != n) {
        cout<<-1<<endl;
    }
    else {
        for(int i=0;i<v.size();i++){
            cout<<v[i]+1<<" ";
        }cout<<endl;
    }
    return 0;
}
