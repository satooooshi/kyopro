#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    ll ans=1000000000+1;
    for(int i=0;i<=2*max(x,y);i++){// AB piza maisuu i mai wo kimeuti
        ll ra=(x-i/2>0)?(x-i/2):0;
        ll rb=(y-i/2>0)?(y-i/2):0;
        ll t=i*c+ra*a+rb*b;
        ans=min(ans,t);
    }

    cout<<ans<<endl;


    return 0;
}
