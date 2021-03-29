// C - City Savers
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// a1=min(a1-b1,0)
// a2=min(a1+a2-b1,0)
// ...
// ai=min(ai+ai+1-bi,0)

int main(){

    int n;
    cin>>n;
    vector<ll>a,b;
    for(int i=0;i<n+1;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        b.push_back(x);
    }

    ll cnt=a[0]-min(abs(a[0]-b[0]),0LL);
    cout<<0<<":"<<cnt<<endl;
    for(int i=1;i<n+1;i++){
        cnt+=a[i]-min(abs(a[i-1]+a[i]-b[i-1]),0LL);
        cout<<i<<":"<<a[i]-min(abs(a[i-1]+a[i]-b[i-1]),0LL)<<endl;
    }
    cout<<cnt<<endl;



    return 0;
}
