#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    ll k;
    cin>>k;

    vector<pair<ll,ll>>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end());

    ll cnt=0;
    for(auto it=v.begin();it!=v.end();it++){
        cnt+=it->second;
        if(cnt>=k){
            cout<<it->first<<endl;
            return 0;
        }
    }





    return 0;
}