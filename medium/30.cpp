// C - Flip,Flip, and Flip......
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,m;
    cin>>n>>m;
    ll res=-1;
    if(n==1&&m>1){
        res=(n-2)*3+2*2;
    }else if(m==1&&n>1){
        res=(m-2)*3+2*2;
    }else if(n==2&&m>2){
        res=(n-2)*m*6+4*4;
    }else if(m==2&&n>2){
        res=(m-2)*n*6+4*4;
    }else{
        res=(2*(n-2)+2*(m-2))*6+4*4+(m*n-2*(n-2)-2*(m-2)-4)*9;
    }

    cout<<res<<endl;


    return 0;
}
