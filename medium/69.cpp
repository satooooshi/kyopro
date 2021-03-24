// C - Five Transportations
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n;
    cin>>n;
    ll mi=1000000000000000+1;
    for(int i=0;i<5;i++){
        ll x;
        cin>>x;
        mi=min(mi,x);
    }
    cout<<4+(n + mi - 1) / mi<<endl; // round up




    return 0;
}

