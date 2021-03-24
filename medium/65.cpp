// A - Two Abbreviations
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// gcd, lcm
// a と b の最大公約数を返す関数
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main(){
    ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;

    // gl==nm
    ll g=gcd(n,m);
    ll l=lcm(n,m);
    bool ok=true;
    for(ll i=0;i<g;i++){
        // ex. n6 m3 l6 g3
        // S[6]==X"0",1,"2",3,"4",5
        // T(3)==X"0","2","4"
        // that is s[i*n/g]==t[i*m/g]
        if(s[i*n/g]!=t[i*m/g])ok=false;
    }
    if(ok)cout<<l<<endl;
    else cout<<-1<<endl;
    


    return 0;
}
