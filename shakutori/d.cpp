#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    ll n,W;
    cin>>n>>W,W;
    vector<ll>v(n),w(n);
    vector<ll>dp(W+1,0);
    for(ll i=0;i<n;i++){
        cin>>v[i]>>w[i];
    }
    

    for(ll i=0;i<n;i++){
        for(ll j=w[i];j<=W;j++){
            if(j-w[i]>=0){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    }

    cout<<*max_element(dp.begin(),dp.end())<<endl;

    return 0;
}