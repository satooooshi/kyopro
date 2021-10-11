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


// morau dp,initial value in dp0,0, if-constraint, cusum s0=0, sj is sum of dpi,[0,j), 3001+1 for loop

int main(){

    int n;cin>>n;
    vector<int>a(n),b(n);
    for(auto &e:a)cin>>e;
    for(auto &e:b)cin>>e;

    // morau dp
    vector<vector<ll>>dp(n+1,vector<ll>(3001,0));
    dp[0][0]=1;
    for(int i=1;i<n+1;i++){
        // cusum
        vector<ll>s(3001+1,0);//s[0]=0; sj is sum of dp,[0..j) NOT contain right end!!
        for(int j=0;j<3001+1;j++){
            s[j+1]=s[j]+dp[i-1][j];
            s[j+1]%=998244353;
        }
        for(int j=0;j<3001;j++){
            if(a[i-1]<=j&&j<=b[i-1]){
                dp[i][j]=s[j]+dp[i-1][j];
                dp[i][j]%=998244353;
            }
        }
    }

    ll res=0;
    for(int j=0;j<3001;j++){
        res+=dp[n][j];
        res%=998244353;
    }
    cout<<res<<endl;

    return 0;
}


/*
    // morau dp
    vector<vector<ll>>dp(n+1,vector<ll>(3001,0));
    dp[0][0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<3001;j++){
            for(int k=0;k<3001;k++){
                if(k<=j&&a[i-1]<=j&&j<=b[i-1]){
                    dp[i][j]+=dp[i-1][k];
                    cout<<i<<","<<j<<" += "<<i-1<<","<<k<<endl;
                    cout<<"dp "<<i<<": "<<dp[i][j]<<endl;
                }
            }
            
        }
    }
    
    ll res=0;
    for(int j=0;j<3001;j++){
        res+=dp[n][j];
        res%=998244353;
    }
    cout<<res<<endl;


*/
