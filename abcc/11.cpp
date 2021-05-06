// C - Mandarin Orange
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
    vector<int>v(n);
    rep(i,n){
        cin>>v[i];
    }

    int ans=0;
    for(int l=0;l<n;l++){
        int mn=v[l];
        for(int r=l;r<n;r++){ 
            mn=min(mn,v[r]);// [l,r]
            int cnt=mn*(r-l+1);
            //cout<<l<<" "<<r<<" "<<cnt<<endl;
            ans=max(ans,cnt);
        }
    }

    cout<<ans<<endl;


    return 0;
}
