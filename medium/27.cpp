// A - Sorted Arrays
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
    }

    int res=0; // count nods
    int i=0;
    for(;i<n-1;){ // i<n-1 -> i+1<n tonaru
        if(a[i]<a[i+1])while(a[i]<a[i+1])i++;
        else while(a[i]>a[i+1])i++;
        res++;
        i++;
        // cout<<"i:"<<i<<endl;
    }
    if(i<=n-1)res++; // count seq with just last elem
    cout<<res<<endl;

    return 0;
}
