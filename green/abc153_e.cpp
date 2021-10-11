#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



int main() {

    int h,n;cin>>h>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    // dpi,j:= 前からi個のいくつか使って、モンスターの残りのライフがjの時のコストの最小値
    // 何個使ってもいいナップサック問題！！
    int MAX=10101;
    vector<vector<int>>dp(MAX, vector<int>(MAX,inf));

    dp[0][h]=0;
    for(int i=0;i<=n;i++){
        for(int j=h;j>=0;j--){
            chmin(dp[i][max(0,j-a[i])],dp[i][j]+b[i]);// use i th magic 
            chmin(dp[i+1][j],dp[i][j]);// dont use i th magic anynmore
            // max(0,j-a[i])0以下もゼロにまとめる
        }
    }


    cout<<dp[n][0]<<endl;


    return 0;
 }
