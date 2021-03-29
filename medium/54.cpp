// A - Airport Bus
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll>v;
    rep(i,n){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    ll res=0;
    for(int i=0;i<n;){
        ll l=v[i]; // hajime no kyaku wo kiroku
        ll cnt=0;
        while(i<n&&v[i]-l<=k&&cnt<c){ // kokode jissaini hajime no kyakukara noseru
            cnt++;
            //cout<<"bus#:"<<res<<",Vi:"<<v[i]<<",cntInThisBus:"<<cnt<<endl;
            i++;
        }
        res++;
        
    }

    cout<<res<<endl;


    return 0;
}
