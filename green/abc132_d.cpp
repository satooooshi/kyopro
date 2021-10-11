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

ll mod = 1000000007;
//---------------------------------------------------------------------------------------------------
ll C(int n, int k) {
    ll a = 1; // = n!
    ll b = 1; // = (n-k)!
    ll c = 1; // = k!

    rep(i, 0, n) a = (a * (n - i)) % mod;
    rep(i, 0, n - k) b = (b * (n - k - i)) % mod;
    rep(i, 0, k) c = (c * (k - i)) % mod;

    ll bc = (b * c) % mod;

    return (a / bc) % mod;
}


int main() {

    int n,k;cin>>n>>k;
    ll mod =1000000007;
    vector<vector<int>>dp(n+100,vector<int>(n+100,0));

    // 1-based indexing, pascal triangle
    // kubarudp
    dp[1][0]=dp[1][1]=1;//1C0,1C1==0
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            //cout<<i<<"C"<<j<<" "<<dp[i][j]<<" ";
            dp[i+1][j]+=dp[i][j];dp[i+1][j]%=mod;
            dp[i+1][j+1]+=dp[i][j];dp[i+1][j+1]%=mod;
        }
        //cout<<endl;
    }

    for(int i=1;i<=k;i++){
        cout<<dp[n-k+1][i]*dp[k-1][i-1]%mod<<endl;
    }

    return 0;
}