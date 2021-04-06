// D - Sum of difference
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    int n;
    cin>>n;
    vector<ll>a(n),b(n+1);
    rep(i,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    b[0]=0;
    for(int i=1;i<n+1;i++){
        b[i]=b[i-1]+a[i-1];
    }
    //for(auto x:a){cout<<x<<" ";}cout<<endl;
    //for(auto x:b){cout<<x<<" ";}cout<<endl;
    // a[left,right)==b[right]-b[left]
    //for(int i=0;i<n;i++){cout<<"a["<<i<<","<<n-1<<"]:"<<b[n]-b[i]<<endl;}
    ll cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(n-1-i)*a[i]-(b[n]-b[i+1]);
        //cout<<"a["<<i<<","<<n-1<<"]:"<<b[n]-b[i]<<endl;
    }
    cout<<cnt<<endl;

    return 0;
}
