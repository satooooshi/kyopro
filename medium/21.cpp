// Banned K

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<ll>a;
    map<ll,int>m;
    ll res=0;
    rep(i,n){
        int x;
        cin>>x;
        a.push_back(x);
        res+=m[x];
        m[x]++;
    }
    //cout<<"res:"<<res<<endl;

    for(auto x:a){
        cout<<res-(m[x]-1)<<endl;
    }

    



    return 0;
}