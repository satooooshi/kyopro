// B - すぬけ君の塗り絵 2 イージー 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int w,h,n;
    cin>>w>>h>>n;
    int l=0,r=w,t=h,b=0;

    rep(i,n){
        int x,y,a;
        cin>>x>>y>>a;
        if(a==1){
            if(r<x){cout<<0<<endl;return 0;}
            l=max(l,x);
        }else if(a==2){
            if(x<l){cout<<0<<endl;return 0;}
            r=min(r,x);
        }else if(a==3){
            if(t<y){cout<<0<<endl;return 0;}
            b=max(b,y);
        }else{
            if(y<b){cout<<0<<endl;return 0;}
            t=min(t,y);
        }
    }

    cout<<(t-b)*(r-l)<<endl;



    return 0;
}
