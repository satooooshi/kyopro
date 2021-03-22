#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,m;
    cin>>n>>m;

    int cnt=0;
    if(2*n<=m){
        // use  all S and cc
        cnt+=n;
        m-=2*n;
        // use cccc
        cnt+=m/4;
    }else{
        // use cccc
        cnt+=m/4;
        m-=cnt*4;
        // use some S and cc
        cnt+=m/2;
    }
    cout<<cnt<<endl;


    return 0;
}
