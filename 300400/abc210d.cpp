#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

//---------------------------------------------------------------------------------------------------
template<typename T> vector<vector<T>> rotateClockwise(vector<vector<T>> g) {
    int n = g.size();
    int m = g[0].size();
    vector<vector<T>> res(m, vector<T>(n));
    rep(i, 0, n) rep(j, 0, m) res[j][n - i - 1] = g[i][j];
    return res;
}
//---------------------------------------------------------------------------------------------------

int h,w,c;
vector<vector<int>>a;// 0-indexed


ll solve(){
    vector<vector<ll>>dp(h,vector<ll>(w,inf));// dpi,j:= min of range (0,0)-(i,j), 0-indexed
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dp[i][j]=a[i][j]-(ll)c*(i+j+2);
            //cout<<i+1<<","<<j+1<<":"<<dp[i][j]<<endl;
            if(i-1>=0){
                dp[i][j]=min(dp[i][j], dp[i-1][j]);
            }
            if(j-1>=0){
                dp[i][j]=min(dp[i][j], dp[i][j-1]);
            }
        }
    }

    //cout<<dp[h-1][w-1]<<endl;

    ll res=infl;
    for(int i=0;i<h;i++){// 右下の点 ES
        for(int j=0;j<w;j++){
            ll right=infl;//左上の点 !=右下の点
            if(i-1>=0){
                right=min(right, (ll)dp[i-1][j]);
            }
            if(j-1>=0){
                right=min(right, (ll)dp[i][j-1]);
            }
            ll left=a[i][j]+(ll)c*(i+j+2);//右下の点
            res=min(res,(ll)left+right);
        }
    }
    //cout<<res<<endl;
    return res;
}

int main() {

    
    cin>>h>>w>>c;
    a.resize(h,vector<int>(w));
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    ll ans = infl;
    rep(_, 0, 2) {
        chmin(ans, solve());
        a = rotateClockwise(a);
        swap(h, w);
    }
    cout << ans << endl;


    return 0;
}