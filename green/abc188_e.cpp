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

int main(){

    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n);// nodes 0-indexed
    vector<ll>a(n);
    for(auto &e:a)cin>>e;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x-1].push_back(y-1);
    }

    //dp by topo order (<-->) DAG
    // topo adj list(vector not matrix)
    //　配るDP（親dpiをその子dpjへ配る, adj[i-1].push_back(j-1)）
    vector<ll>dp(n,infl);
    for(int i=0;i<n;i++){
        for(auto j:adj[i]){
            dp[j]=min(dp[j],min(dp[i],a[i]));
        }
    }

    ll res=-infl;
    for(int i=0;i<n;i++){
        res=max(res,a[i]-dp[i]);// dp[i]円で買って、a[i]円で売る
    }
    cout<<res<<endl;
    return 0;
}
