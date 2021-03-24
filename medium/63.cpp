// B - すぬけ君の塗り絵 2 イージー
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n,w,h;
    cin>>n>>w>>h;
    cin>>w>>w>>n;
    int l=0,r=w,b=0,t=h;

    rep(i,n){
        int x,y,a;
        cin>>x>>y>>a;
        if(a==1&&l<=x)r=min(r,x);
        else if(a==2&&x<=r)l==max(l,x);
        else if(a==3)b=max(b,y);
        else t=min(t,y);
    }

    cout<<(r-l)*(t-b)<<endl;




    return 0;
}
