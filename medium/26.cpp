//A - Sorted Arrays
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n;
    cin>>n;
    vector<ll>v;
    rep(i,n){
        ll x;
        cin>>x;
        v.push_back(x);
    }

    // [left,right]
    ll res=0;
    ll l=0;
    for(int i=1;i<n;){
        while(i<n&&v[i-1]==v[i])i++;
        if(i<n&&v[i-1]<v[i])while(i<n&&v[i-1]<v[i])i++;
        else while(i<n&&v[i-1]>v[i])i++;
        ll r=i-1;
        cout<<"["<<l<<","<<r<<"]"<<endl;
        res++;
        l=i;
    }
    cout<<res<<endl;




    return 0;
}
