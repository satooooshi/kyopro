#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>p;
    rep(i,n){
        int x;
        cin>>x;
        p.push_back(x);
    }

    ll res=0;
    for(int i=0;i<n;i++)
    {
        ll l=i;
        while(p[i]==i+1)i++;
        ll r=i;
        ll cnt=r-l;
        //cout<<"["<<l<<","<<r<<"), "<<cnt<<" ko"<<endl;
        res+=(cnt+1)/2;// round up to multiple of 2
    }
    cout<<res<<endl;


    return 0;
}
