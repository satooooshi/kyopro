// B - Exactly N points
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
    vector<ll>a(n),b(n+1),res;
    b[0]=0;
    for(int i=0;i<n;i++){
        a[i]=i+1;
        b[i+1]=b[i]+a[i];
    }
    //rep(i,n){cout<<a[i]<<" ";}cout<<endl;
    //rep(i,n+1){cout<<b[i]<<" ";}cout<<endl;

    while(true){
        auto it=lower_bound(b.begin(),b.end(),n);
        ll i=it-b.begin();
        if(i==0)break;
        //cout<<"i:"<<i<<", bi:"<<b[i]<<", push ai "<<a[i-1]<<endl;
        res.push_back(a[i-1]);
        n-=a[i-1];
    }
    for(auto x:res){cout<<x<<" ";}cout<<endl;


    return 0;
}
