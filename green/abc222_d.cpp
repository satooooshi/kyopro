#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



int main(){

    int n;cin>>n;
    vector<int>a(n),b(n);
    for(auto &e:a)cin>>e;
    for(auto &e:b)cin>>e;

    // kubaru dp
    vector<vector<ll>>dp(n+10,vector<ll>(3001,0));
    for(int j=a[0];j<=b[0];j++){
        dp[0][j]=1;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<3001;j++){
            for(int k=0;k<3001;k++){
                if(j<=k&&a[i+1]<=k&&k<=b[i+1]){ // simplify dp by adding constraint-if rather than specific start point in for-loop
                    dp[i+1][k]+=dp[i][j];
                    dp[i+1][k]%=998244353;
                }

            }
        }
    }

    ll res=0;
    for(int j=0;j<3001;j++){
        res+=dp[n-1][j];
        res%=998244353;
    }

    cout<<res<<endl;

    return 0;
}

/*
    vector<vector<ll>>dp(n+10,vector<ll>(n+10,0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++) 
        for(int lst=0;lst<3001;lst++) 
            for(int nxt=lst;nxt<3001;nxt++) {
                if (a[i] <= nxt && nxt <= b[i]) 
                    dp[i + 1][nxt] += dp[i][lst];
            }

    ll res=0;
    for(int j=0;j<3001;j++){
        res+=dp[n][j];
        res%=998244353;
    }

    cout<<res<<endl;

*/