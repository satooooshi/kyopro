#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



int main() {

    int n;cin>>n;
    int x,y;cin>>x>>y;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    // O(NXY)
    // 配るDP
    // dpi,j,k:= 前からithまででいくつか使って、j以上　min(x,j+a[i]),k以上min(y,k+b[i])達成する時の個数の最小値
    vector<vector<vector<int>>>dp(310,
        vector<vector<int>>(310,
            vector<int>(310,inf)));
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            for(int k=0;k<=y;k++){
                dp[i+1][min(x,j+a[i])][min(y,k+b[i])]=min(dp[i+1][min(x,j+a[i])][min(y,k+b[i])], dp[i][j][k]+1);// i th 使う
                dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);// i th 使わない
            }
        }
    }

    if(dp[n][x][y]!=inf){
        cout<<dp[n][x][y]<<endl;
    }else{
        cout<<-1<<endl;
    }
   
    return 0;
}
