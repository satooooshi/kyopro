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

using Graph = vector<vector<int>>;// adjacent matrix
int n,m;
Graph g;

vector<int> dfs(int v){
    vector<bool> seen(n, false);  // 既に見たことがある頂点か記録する
    vector<int> dist(n, inf); 
    stack<int> st;
    seen[v] = true;
    dist[v]=0;
    st.emplace(v);  // sから探索する
    while (st.size() != 0) {   // 深さ優先探索
        int state = st.top();  // 現在の状態
        st.pop();
        for (int next=0;next<n;next++)if(g[state][next]==1){
            if (!seen[next]) {  // 未探索の時のみ行う
                seen[next]=true;
                dist[next]=dist[state]+1;
                st.emplace(next);  //次の状態をqueueへ格納
            }
        }
    }
    return dist;
}

int main(){

    cin>>n>>m;
    g.assign(n,vector<int>(n,0));
    for(int i=0;i<m;i++){// adjacent matrix
        int a,b;cin>>a>>b;
        a--;
        b--;
        g[a][b]=1;
        g[b][a]=1;
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)if(g[i][j]==1){
            g[i][j]=0;
            vector<int>dist=dfs(0);
            for(auto e:dist){
                if(e==inf){
                    cnt++;
                    break;
                }
                
            }
            g[i][j]=1;
        }
    }
    cout<<cnt<<endl;

    return 0;
}

