#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){

    int n,m;

    cin>>n>>m;

    bool g[n+1][n+1]{false};// 1-based index
    /*
    rep(i,n){
        rep(j,n){
            cout<<g[i][j];
        }
    }
    */

    rep(i,m){
        int a,b;
        cin>>a>>b;
        g[a][b]=true;// mukou graph
        g[b][a]=true;
    }

    vector<int>a(n);
    iota(a.begin(),a.end(),1);

    int cnt=0;
    do{
        if(a[0]!=1)continue;//traverse from node 1

        bool ok=true;
        for(int i=1;i<n;i++){
            if(g[a[i]][a[i-1]]==false){
                ok=false;
                break;
            }
        }

        if(ok)cnt++;

    }while(next_permutation(a.begin(),a.end()));
    
    cout<<cnt<<endl;



    return 0;
}
