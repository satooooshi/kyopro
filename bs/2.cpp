// widespread
// f()<=X damages

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


bool check(ll x, vector<ll> &h, ll a, ll b){
    sort(h.begin(),h.end(), greater<ll>());
    ll dmg=0;
    for(int i=0;i<h.size();i++){
        if(i==0){
            dmg+=min(h[i],a);
            h[i]=(h[i]<a)?0:(h[i]-a);
        }else{
            dmg+=min(h[i],b);
            h[i]=(h[i]<a)?0:(h[i]-b);
        }
    }
    if(dmg<=x)return true;
    else return false;
}

int main(){

    int n;
    ll a,b;
    cin>>n>>a>>b;
    vector<ll>h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    
    ll left=1,right=1000000000+1;//right a=1, n=10^9, max(hi)/a
    ll mid=(left+right)/2;

    while(right-left>1){
        if(check(mid, h, a, b))
            right=mid;
        else
            left=mid;
        
        cout<<mid<<endl;
    }

    cout<<mid<<endl;

    return 0;
}