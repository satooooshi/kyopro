// C. Not so Diverse
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){

    ll n,k;
    cin>>n>>k;
    map<ll,ll>m;
    rep(i,n){
        int a;
        cin>>a;
        m[a]++;
    }

    vector<pair<ll,ll>>v; // pair<cnt,num>
    for(auto a:m){
        v.push_back({a.second,a.first}); // cnt, num
        // cout<<"num:"<<a.first<<"cnt:"<<a.second<<endl;
    }
    sort(v.begin(),v.end());
    int res=0;
    int i=0;
    while(m.size()>k){
        res+=v[i].first;
        m.erase(v[i].second);
        i++;
    }
    cout<<res<<endl;


    return 0;
}


// bekkai
// backet sort desc
// kaku suuji ooi hou kara K shurui toru