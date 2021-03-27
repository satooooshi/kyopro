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
    ll l=0,i=1;
    bool up=false;
    ll cnt=0;
    if(v[0]<=v[1])up=true;
    while(i<n){
        if(up)while(i<n&&v[i-1]<=v[i])i++;
        else while(i<n&&v[i-1]>=v[i])i++;
        ll r=i-1;
        cnt++;
        cout<<"["<<l<<","<<r<<"], cnt:"<<cnt<<endl;
        l=i;
        if(i+1<n){
            if(v[i]<v[i+1])up=true;
            else up=0;
        }else{
            break;
        }

    }

    cout<<cnt<<endl;




    return 0;
}
