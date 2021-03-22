// C - Rectangle Cutting
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    ll w,h,x,y;
    cin>>w>>h>>x>>y;

    int p=0;
    if(x+x==w&&y+y==h)p=1;
    double a=w*h/2.0;
    cout<< std::fixed << std::setprecision(8) <<a<<" "<<p<<endl;


    return 0;
}