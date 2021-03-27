// A - Prefix and Suffix
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int res=2*n;
    for(int i=1;i<=n;i++){
        int len=i;
        int si=n-i;
        if(s.substr(si)==s.substr(0,len)){
            res=min(res,2*n+(n-si));
            cout<<s.substr(si)<<","<<s.substr(0,len)<<", min:"<<res<<endl;
        }
    }

    cout<<res<<endl;


    return 0;
}