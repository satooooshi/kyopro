// C - Many Medians
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n;
    cin>>n;
    vector<ll>a,b;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
        b.push_back(x);
    }
    sort(b.begin(),b.end());
    ll mid=b[n/2];
    for(int i=0;i<n;i++){
        if(a[i]<b[mid])cout<<b[mid]<<endl;
        else cout<<b[mid-1]<<endl;
    }


    return 0;
}