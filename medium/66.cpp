// A - Multiple Array
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<pair<ll,ll>>v;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    ll res=0;
    for(int i=n-1;i>=0;i--){
        //cout<<v[i].first+res<<","<<v[i].second<<endl;
        int x=0;
        if((v[i].first+res)%v[i].second==0)continue; // already ok
        if(v[i].first+res<v[i].second){
            x=v[i].second-(v[i].first+res);
        }else{
            x=v[i].second-(v[i].first+res)%v[i].second;
        }
        res+=x;
    }
    cout<<res<<endl;



    return 0;
}
