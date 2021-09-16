#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using Graph = vector<vector<int>>;
// 深さ優先探索
vector<bool> seen;  // 既に見たことがある頂点か記録
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next : G[v]) {
        if (!seen[next]) {  // 訪問済みでなければ探索
            dfs(G, next);
        }
    }
}
int main() {
    int V, E;
    cin >> V >> E;

    Graph G(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back({b});
        // G[b].push_back({a});
    }

    ll res=0;
    for(int i=0;i<V;i++){
        seen.assign(V, false);  // 初期化
        dfs(G, i);
        for(int j=0;j<V;j++){
            if(seen[j]){
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}