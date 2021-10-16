//dfs, adjacent list(vector)(頂点数多くて、変数が比較的少ない時)・再帰関数
// ATTENTION!! node# 0-indexed

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

/*
int N, C[101010];
vector<int> E[101010];
//---------------------------------------------------------------------------------------------------
int cnt[101010];
bool good[101010];
void dfs(int cu, int pa = -1) {
    if (cnt[C[cu]] == 0) good[cu] = true;
    cnt[C[cu]]++;

    fore(to, E[cu]) if (to != pa) {
        dfs(to, cu);
    }

    cnt[C[cu]]--;
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N;
    rep(i, 0, N) cin >> C[i];
    rep(i, 0, N - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    dfs(0);
    rep(i, 0, N) if(good[i]) printf("%d\n", i + 1);

return 0;
}
*/


int n,m;
vector<int>c;
vector<int>colored;// colored i is used or not
vector<int>res;
bool good[101010];

// 深さ優先探索 dfs
using Graph = vector<vector<int>>;
//vector<bool> seen;  // 既に見たことがある頂点か記録
Graph G;

void dfs(int v, int p=-1) {
    //seen[v] = true;
    if(colored[c[v]]==0)res.push_back(v);
    colored[c[v]]++;
    for (int next : G[v])if(next!=p){
        //if (seen[next])continue;   // 訪問済みでなければ探索
        dfs(next, v);
    }
    //res.push_back(v); // pushes from leaf to the root
    colored[c[v]]--;
}

int main() {

    cin>>n;
    G.resize(n);//0-indexed
    m=n-1; // tree
    c.resize(n);
    colored.resize(101010);//assign(n,0);
    for(int i=0;i<n;i++)cin>>c[i];
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //seen.assign(n, false);  // 初期化
    dfs(0);
    sort(res.begin(),res.end());
    for(auto e:res)cout<<e+1<<endl;

    return 0;
}
