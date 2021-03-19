// C - Together
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    map<int,int>m;
    rep(i,n){
        int a;
        cin>>a;
        m[a-1]++;
        m[a]++;
        m[a+1]++;
    }

    int res=0;
    for(auto a:m){
        if(res<a.second){
            res=a.second;
        }
    }
    cout<<res<<endl;
    return 0;
}