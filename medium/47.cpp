// A - Biscuits
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    /* bit not enough need N:50 bits!!
    int n,p;
    cin>>n>>p;
    vector<int>a(n);
    rep(i,n){
        cin>>a[i];
    }
    ll res=0;
    for(ll bit=0;bit<(1<<n);bit++){
        ll x=0;
        for(int i=0;i<n;i++){
            if(!(bit&(1<<i)))continue;
            x+=a[i];
        }
        if(x%2==p)res++;
    }
    cout<<res<<endl;
    */


    return 0;
}
