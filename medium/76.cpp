// C - Attention
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
    string s;
    cin>>s;
    ll len=s.length();

    vector<ll>a(n+1),b(n+1);
    a[0]=0;
    for(int i=1;i<n+1;i++){
        if(s[i-1]=='W'){
            a[i]=a[i-1]+1;
        }else{
            a[i]=a[i-1];
        }
    }
    reverse(s.begin(),s.end());
    for(int i=1;i<n+1;i++){
        if(s[i-1]=='E'){
            b[i]=b[i-1]+1;
        }else{
            b[i]=b[i-1];
        }
    }
    //for(auto x:a){cout<<x;}cout<<endl;
    //for(auto x:b){cout<<x;}cout<<endl;
    ll res=a[0]+b[n-1];
    for(int i=0;i<n;i++){
        int j=n-i-1;
        res=min(res,a[i]+b[n-1-i]);
    }
    cout<<res<<endl;
    





    return 0;
}
