#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

class UnionFind {
public:
    vector < ll > par; // 各元の親を表す配列
    vector < ll > siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

int V, E;
vector<vector<int>> G(V+1);
vector<bool> seen(V+1, false);  // 既に見たことがある頂点か記録する, 1-based indexing

void dfs(int s){

    stack<int> st;
    st.emplace(s);  // sから探索する
    seen[s] = true;
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

}

/*
ll calc(){
    ll ret=1;
    for(n:s){
        int cnt=3;
        for(v:g[n]){
            if(seen[v]){
                cnt--;
                if(cnt==0)return 0;
            }
        }
        ret*=cnt;
    }
    return 0;
}
*/

int main() {
    
    cin >> V >> E;
   
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back({b});
        G[b].push_back({a});
        // uf.merge(A, B);
    }


    ll ans=1;
    // union-find  で　連結グラフごとに root 
    // for(rt:par)rootset.insert(rt);
    // for(rt:rootset){
        //vector seen,s;
        //dfs(rt); fills s array
        //ans*=calc(seen,s);
        
    cout<<ans<<endl;




    return 0;
}