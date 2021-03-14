#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll h,w;
    cin>>h>>w;

    if(h==1||w==1){
        cout<<1<<endl;
        return 0;
    }

    if(h*w&1){
        cout<<h*w*1/2+1<<endl;
    }else{
        cout<<h*w*1/2<<endl;
    }

    return 0;
}

