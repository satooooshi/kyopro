// A - Prefix and Suffix
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    ll res=2*n;
    for(ll len=1;len<=n;len++){
        ll si=n-len;
        if(s.substr(si)==t.substr(0,len)){
            //cout<<s.substr(si)<<","<<t.substr(0,len)<<", "<<2*n<<"-"<<len<<"="<<2*n-len<<endl;
            res=min(res,2*n-len);
        }
    }

    cout<<res<<endl;


    return 0;
}