// C - Make a Rectangle
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    // substitute this for backet sort for large backet
    int n;
    cin>>n;
    map<ll,ll>m;
    rep(i,n){
        ll x;
        cin>>x;
        m[x]++;// 4 same length:a bars --> a*a 
    }
    vector<ll>a;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>=4){
            a.push_back(it->first);
            a.push_back(it->first);
        }else if(it->second>=2)
            a.push_back(it->first);
    }
    sort(a.begin(),a.end(),greater<ll>());

    if(a.size()>=2){
        cout<<a[0]*a[1]<<endl;
    }else{
        cout<<0<<endl;
    }




    return 0;
}

