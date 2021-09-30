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
    int n,k;cin>>n>>k;
    string T;cin>>T;
    vector<int>t; // r0,s1,p2
    for(int i=0;i<T.length();i++){
        if(T[i]=='r')t.push_back(0);
        else if(T[i]=='s')t.push_back(1);
        else t.push_back(2);
    }
    int r,s,p;cin>>r>>s>>p;
    vector<vector<int>>pt(3,vector<int>(3,0)); // r, s, p
    pt[0][2]=p;//rock paper
    pt[1][0]=r;// scesor rock
    pt[2][1]=s;// paper rock

    vector<vector<int>>dp(n,vector<int>(3,0));
    for(int i=0;i<k;i++){
        if(T[i]=='r') dp[i][t[i]]=pt[t[i]][2];
        else if(T[i]=='s') dp[i][t[i]]=pt[t[i]][0];
        else dp[i][t[i]]=pt[t[i]][1];
        
    }
    for(int i=0;i+k<n;i++){
        for(int j=0;j<3;j++){
            dp[i+k][(j+1)%3]=max(dp[i+k][(j+1)%3],dp[i][j]+pt[t[i+k]][(j+1)%3]);
            dp[i+k][(j+2)%3]=max(dp[i+k][(j+1)%3],dp[i][j]+pt[t[i+k]][(j+2)%3]);
        }
    }    

    int res=-1;
    ll ans=0;
    for(int i=0;i<k;i++){
        res=max(res,max(dp[n-1-i][0],max(dp[n-1-i][1],dp[n-1-i][2])));
        ans+=res;
    }
    cout<<ans<<endl;
    return 0;
}
