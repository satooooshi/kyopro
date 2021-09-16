#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    int n;cin>>n;
    vector<int>t(n);
    ll tot=0;
    for(int i=0;i<n;i++){
        cin>>t[i];
        tot+=t[i];
    }

    vector<vector<int>>dp(n+1, vector<int>(1000*100*10, -1));
    dp[0][0]=1;
    //  配るDP, i,j -> i+1,j+ti and i+1,j
    for(int i=0;i<n;i++){
        for(int j=0;j<1000000;j++){
            if(dp[i][j]!=-1){
                dp[i+1][j]=dp[i][j];
                dp[i+1][j+t[i]]=dp[i][j];
                //cout<<i+1<<","<<j<<":"<<dp[i+1][j]<<endl;
                //cout<<i+1<<","<<j+t[i]<<":"<<dp[i+1][j+t[i]]<<endl;
            }
        }
    }

    ll res=0;
    for(int j=tot/2;j<1000000;j++){
        if(dp[n][j]==1){
            res=j;
            break;
        }
    }
    cout<<max(res,tot-res)<<endl;


    return 0;
}