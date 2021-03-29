// C - Green Bin
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    map<string,int>m;
    ll res=0;
    rep(i,n){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        res+=m[s];
        m[s]++;
    }
    cout<<res<<endl;


    return 0;
}

