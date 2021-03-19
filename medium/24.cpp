// A - A+...+B Problem
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,a,b;
    cin>>n>>a>>b;

    if(n==1&&a!=b){
        cout<<0<<endl;
        return 0;
    }

    if(a==b){
        cout<<1<<endl;
        return 0;
    }

    if(a>b){
        cout<<0<<endl;
        return 0;
    }

    

    ll mn=a*(n-1)+b,mx=a+b*(n-1);
    cout<<mx-mn+1<<endl;





    return 0;
}
