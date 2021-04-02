// A - Simple Calculator
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    ll x,y;
    cin>>x>>y;

    string m;
    pair<ll,ll>p;

    ll cnt=-1;
    ll res=1000000000+10;
    if(x+(y-x)==y){ // a
        cnt=y-x;
        if(res>cnt&&cnt>=0){
            res=cnt;
            m="a";
            p={x,y};
        }
    }
    if(x+(y-x)==y){ // ba
        cnt=abs(y-(-x))+1;
        if(res>cnt&&cnt>=0){
            res=cnt;
            m="ba";
            p={x,y};
        }
    }
    if(x+abs(x+y)==-y){ // ab
        cnt=abs(x+y)+1;
        if(res>cnt&&cnt>=0){
            res=cnt;
            m="ab";
            p={x,y};
        }
    }
    if(x==-y){ // b
        cnt=1;
        if(res>cnt&&cnt>=0){
            res=cnt;
            m="b";
            p={x,y};
        }
    }
    if(x-abs(y-x)==y){ //bab
        cnt=1+abs(-x+y)+1;
        if(res>cnt&&cnt>=0){
            res=cnt;
            m="bab";
            p={x,y};
        }
    }


    
    //cout<<m<<", {"<<p.first<<","<<p.second<<"}"<<endl;

    cout<<res<<endl;

    return 0;
}


