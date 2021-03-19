// C - Write and Erase

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    
    ll n;
    cin>>n;
    map<ll,ll>m;
    rep(i,n){
        int a;
        cin>>a;
        m[a]++;
    }
    ll cnt=0;
    for(auto x:m){
        if((x.second&1)){
            cnt++;
        }
    }

    cout<<cnt<<endl;


    return 0;
}