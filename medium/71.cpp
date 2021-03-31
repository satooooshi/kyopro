// C - Splitting Pile
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];

    vector<ll>b(n+1),c(n+1);
    b[0]=0;
    c[0]=0;
    for(int i=1;i<n+1;i++){
        b[i]=b[i-1]+a[i-1];
        int j=n-i;
        c[i]=c[i-1]+a[j];
    }
    //for(int i=0;i<n+1;i++){cout<<"b"<<i<<":"<<b[i]<<" ";}cout<<endl;
    //for(int i=0;i<n+1;i++){cout<<"c"<<i<<":"<<c[i]<<" ";}cout<<endl;

    ll res=abs(b[1]-c[n-1]);
    for(int i=1;i<=n-1;i++){
        int j=n-i;
        //cout<<b[i]<<"-"<<c[j]<<"="<<abs(b[i]-c[j])<<endl;
        res=min(res,abs(b[i]-c[j]));
    }
    cout<<res<<endl;

    return 0;
}

