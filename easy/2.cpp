#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>x(n);
    rep(i,n){
        cin>>x[i];
    }

    sort(x.begin(),x.end());

    ll ans=1000000000+1;
    for(int p=x[0];p<=x[n-1];p++){
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=(p-x[i])*(p-x[i]);
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    /*
    //buggy
    int p;
    int left=0,right=n,mid=(left+right)/2;
    if(n&1){
        p=x[mid];
    }else{
        p=(x[mid-1]+x[mid])/2;
    }
    ll ans=0;
    for(auto v:x){
        ans+=((p-v)*(p-v));
    }
    cout<<ans<<endl;
    */


    return 0;
}

