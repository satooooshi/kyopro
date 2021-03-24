// D - Megalomania
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n;
    cin>>n;
    vector<pair<ll,ll>>v;//{b deadline, a needing time}
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }

    sort(v.begin(),v.end());// sort by earliest deadline
    ll ct=0;
    for(auto p:v){
        ct+=p.second;
        if(ct>p.first){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;




    return 0;
}

