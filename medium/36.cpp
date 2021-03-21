// C - Skip
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){

    int n;
    ll x;
    cin>>n>>x;
    vector<ll>v;
    rep(i,n){
        int a;
        cin>>a;
        v.push_back(a);
    }

    ll d=abs(x-v[0]);
    for(int i=1;i<n;i++){
        d=gcd(d,abs(v[i]-x));
    }
    cout<<d<<endl;


    return 0;
}