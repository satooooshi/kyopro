// D - Prediction and Restriction
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    int n,k,r,s,p;
    string t;
    cin>>n>>k>>r>>s>>p>>t;
    int len=t.length();
    map<char,int>point;
    point['r']=r;
    point['s']=s;
    point['p']=p;
    map<char,char>win;
    win['r']='p';
    win['s']='r';
    win['p']='s';
    ll res=0;
    string me;
    rep(i,k){
        me+=win[t[i]];
        res+=point[win[t[i]]];
        cout<<me[i]<<endl;
    }
    for(int i=k;i<n;i++){
        if(me[i-k]!=win[t[i]]){
            me+=win[t[i]];
            res+=point[win[t[i]]];
        }else{ // restriction, give aiko
            me+=t[i];
            //cout<<"same T:"<<i<<":"<<me[i-k]<<endl;
        }
        cout<<me[i]<<endl;
    }
    cout<<res<<endl;



    return 0;
}
