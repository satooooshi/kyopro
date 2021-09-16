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
    int n,q;cin>>n>>q;
    vector<ll>a(n+1),k(q);
    a[0]=0;//sentinel
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<ll>dp(n+1,0);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+(a[i]-a[i-1]-1);
    }
    //for(auto e:dp)cout<<e<<endl;

    for(int i=0;i<q;i++){
        ll x;cin>>x;
        int idx=lower_bound(dp.begin(),dp.end(),x)-dp.begin();
        cout<<a[idx-1]+(x-dp[idx-1])<<endl;
    }

    return 0;
}