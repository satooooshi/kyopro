#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    ll n,k;
    cin>>n>>k;
    vector<ll>s(n);
    for(ll i=0;i<n;i++){
        cin>>s[i];
        if(s[i]==0){cout<<n<<endl;return 0;}
    }
    ll res=0;
    ll right=0;
    ll mul=1;
    for(ll left=0;left<n;left++){
        while(right<n && mul*s[right]<=k){
            mul*=s[right];
            right++;
        }
        res=max(res,right-left);
        if(right==left)right++;
        else mul/=s[left];
    }

    cout<<res<<endl;
    return 0;
}