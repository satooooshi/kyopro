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

int main(){
    
    int n;cin>>n;
    int x,y;cin>>x>>y;

    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }


    // kugaruDP
    //int dp[n+1][301][301];
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(301, vector<int>(301, inf)));
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<301;j++){
            for(int k=0;k<301;k++){
                chmin(dp[i+1][min(x,j+a[i])][min(y,k+b[i])], dp[i][j][k]+1); // i ko me taberu
                chmin(dp[i+1][j][k], dp[i][j][k]);// i ko me tabenai
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