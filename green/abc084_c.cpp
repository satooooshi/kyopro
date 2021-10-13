#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;

int n;
Graph g;//c,s,f
vector<int>c,s,f;


int dfs(int v){
    vector<bool> seen(n, false);  // 既に見たことがある頂点か記録する
    vector<int> dist(n, -1); 
    stack<int> st;
    seen[v] = true;
    dist[v]=0;
    st.emplace(v);  // sから探索する
    while (st.size() != 0) {   // 深さ優先探索
        int state = st.top();  // 現在の状態
        st.pop();
        for (auto e:g[state]) {
            auto next=e.to;
            if (!seen[next]) {  // 未探索の時のみ行う
                seen[next]=true;
                if((dist[state])>=s[state]){
                    // 始発後に到着、次の電車待つ
                    if(dist[state]%f[state]>0){
                        dist[next]=(dist[state]/f[state]+1)*f[state]+c[state];
                    }else{ 
                        dist[next]=(dist[state]/f[state])*f[state]+c[state];
                    }
                }else{ // state駅の始発を待って出発
                    dist[next]=s[state]+c[state];
                }
                st.emplace(next);  //次の状態をqueueへ格納
            }
        }
    }

    return dist[n-1];
}

int main() {
    cin>>n;
    g.resize(n);
    c.resize(n);
    s.resize(n);
    f.resize(n);

    for (int i = 0; i < n-1; i++) {
        cin >>c[i]>>s[i]>>f[i];
        g[i].push_back({i+1});
    }

    for(int i=0;i<n;i++){
        cout<<dfs(i)<<endl;
    }
    
    return 0;
}