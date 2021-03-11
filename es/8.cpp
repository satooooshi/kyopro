#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    // bggy!!S

    ll ans=1000000000+1;
    for(int i=1;i<=max(x,y);i++){// A piza maisuu i wo kimeuti
        ll r=x-i;
        ll tot=i*a+r*2*c+(y-r)*b ;//((y-r)>0?(y-r):0)*b;
        ans=min(tot,ans);
    }

    cout<<ans<<endl;


    return 0;
}
