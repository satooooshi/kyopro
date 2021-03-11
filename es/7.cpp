#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int calc_digitnum(long long N) {
    int res = 0;
    while (N) {
        ++res;
        N /= 10;
    }
    return res;
}

int main(){

    ll n;
    cin>>n;

    ll ans=100;// max #digits is 10
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ll j=n/i;
            ll a=calc_digitnum(i);
            ll b=calc_digitnum(j);
            chmax(a,b);
            ans=min(ans,a);
        }
        
    }

    cout<<ans<<endl;

    return 0;
}
