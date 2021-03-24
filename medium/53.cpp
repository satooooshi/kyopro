// C - Traveling Plan
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
    v.push_back(0);
    for(ll i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    v.push_back(0);
    // now v.size()==n+2
    //for(ll i=0;i<v.size();i++)cout<<"v["<<i<<"] "<<v[i]<<endl;

    

    vector<ll>b;
    for(ll i=1;i<v.size();i++){
        b.push_back(abs(v[i]-v[i-1]));
        //cout<<abs(v[i]-v[i-1])<<endl;
    }
    ll sum=accumulate(b.begin(),b.end(),0);
    //cout<<"sum "<<sum<<endl;
    for(ll i=1;i<v.size()-1;i++){
        //cout<<sum<<"-"<<abs(v[i]-v[i-1])<<"-"<<abs(v[i+1]-v[i])<<"+"<<abs(v[i+1]-v[i-1])<<endl;
        cout<<sum-abs(v[i]-v[i-1])-abs(v[i+1]-v[i])+abs(v[i+1]-v[i-1])<<endl;
    }

    return 0;
}

