// C - Subarray Sum
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,k,s;
    cin>>n>>k>>s;

    ll pad;
    if(s==1000000000)pad=1;
    else pad=s+1;
    rep(i,k){
        cout<<s<<" ";
    }
    rep(i,n-k){
        cout<<pad<<" ";
    }
    cout<<endl;


    return 0;
}
