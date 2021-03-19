// C - Sentou
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,time;
    cin>>n>>time;
    vector<ll>t;
    rep(i,n){
        int x;
        cin>>x;
        t.push_back(x);
    }

    if(n==1){
        cout<<time<<endl;
        return 0;
    }

    ll res=0;
    for(int i=1;i<n;i++){
        if(t[i]-t[i-1]<time){
            res+=t[i]-t[i-1];
        }else{
            res+=time;
        }
    }
    res+=time;

    cout<<res<<endl;


    return 0;
}