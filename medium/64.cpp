// C - Good Sequence

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    map<ll,int>m;
    rep(i,n){
        int x;
        cin>>x;
        m[x]++;
    }
    ll res=0;
    for(auto p:m){
        if(p.first>p.second){
            res+=p.second;
        }else{
            res+=p.second-p.first;
        }
    }
    cout<<res<<endl;


    return 0;
}
