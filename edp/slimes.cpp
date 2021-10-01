// kukan DP must use recursive in post-order traversal template(dfs, stack)
// ruisekiwa
// vector resize, assign, INF=1e18

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;

// kukan dp
const ll INF =1e18;
vector<vector<ll>>dp;
// ruisekiwa
vector<ll>a,b;


ll rec(int l, int r){

    if(r-l==1) return 0; // base condition
    if(dp[l][r]!=INF) return dp[l][r]; // memoka

    // post order traversal, DFS, stack
    for(ll i=l+1;i<r;i++){
        ll nl=rec(l,i);
        ll nr=rec(i,r);
        ll cost=nl+nr+b[r]-b[l];
        dp[l][r]=min(dp[l][r], cost);
    }

    return dp[l][r]; // [l,r)
}


int main(){

    // ruisekiwa, a[left,right)==b[right]-b[left]
    ll n;
    cin>>n;
    dp.assign(n+2,vector<ll>(n+2,INF));
    a.resize(n);
    b.resize(n+1);
    rep(i,n){
        cin>>a[i];
    }
    b[0]=0;
    for(ll i=1;i<n+1;i++){
        b[i]=b[i-1]+a[i-1];
    }
    //for(auto x:b){cout<<x<<" ";}cout<<endl;
    // a[left,right)==b[right]-b[left]
    //for(int i=0;i<n;i++){cout<<"a["<<i<<","<<n-1<<"]:"<<b[n]-b[i]<<endl;}

    cout<<rec(0,n)<<endl;


    return 0;
}
