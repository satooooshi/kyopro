
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

// 深さ優先探索 dfs
using Graph = vector<vector<int>>;
vector<bool> seen;  // 既に見たことがある頂点か記録
void dfs(const Graph &G, int v) {
    seen[v] = true;
    if(v!=0)cout<<" ";
    cout<<v+1;// visited first time
    for (auto next : G[v]) {
        if (!seen[next]) {  // 訪問済みでなければ探索
            dfs(G, next);
            cout<<" "<<v+1;// return from child
        }
    }
    //res.push_back(v); // pushes from leaf to the root
}

int main() {
    int V, E;
    cin >> V;
    E = V-1;
    Graph G(V);//0-indexed
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back({b});
        G[b].push_back({a});
    }
    seen.assign(V, false);  // 初期化

    // 各頂点の隣接頂点を番号が小さい順に
    for (int v = 0; v < V; ++v) {
        sort(G[v].begin(), G[v].end());
    }
    dfs(G, 0);
    cout<<endl;
    return 0;
}

/*

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
 
int N;
vector<int> E[201010];
//---------------------------------------------------------------------------------------------------
void dfs(int cu, int pa = -1) {
    if (cu != 0) printf(" ");
    printf("%d", cu + 1);
 
    fore(to, E[cu]) if (to != pa) {
        dfs(to, cu);
        printf(" %d", cu + 1);
    }
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N;
    rep(i, 0, N - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    rep(i, 0, N) sort(all(E[i]));
    
    dfs(0);
    printf("\n");
  return 0;
}

*/