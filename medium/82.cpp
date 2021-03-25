// C - いっしょ Be Together
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>v(n);
    rep(i,n){
        cin>>v[i];
    }

    ll res=100*200*200+1;
    for(int x=-100;x<=100;x++){
        ll d=0;
        for(int i=0;i<n;i++){
            d+=(v[i]-x)*(v[i]-x);
        }
        res=min(res,d);
    }
    cout<<res<<endl;
    return 0;
}
