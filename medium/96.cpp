// C - Typical Stairs
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;

int main(){

    int n,m;
    cin>>n>>m;
    vector<int>a(100000+1,0);// 1 based indexing, backet
    rep(i,m){
        int x;
        cin>>x;
        a[x]=1;
    }
   
    vector<ll>dp(n+1);
    dp[0]=1;
    if(a[1]==1)dp[1]=0;
    else dp[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==1){// broken
            dp[i]=0;
        }else{
            dp[i]=(dp[i-2]+dp[i-1]);
        }
        dp[i]=dp[i]%mod;
    }
    cout<<dp[n]<<endl;

    return 0;
}
