// C - /\/\/\/ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    int n;
    cin>>n;
    vector<pair<int,int>>b(100000+1);//{cnt,num} 1 based indexing, backet
    rep(i,n){
       int x;
       cin>>x;
       b[x].first+=1;
       b[x].second=x;
    }
    sort(b.begin(),b.end(),greater<pair<int,int>>());
    //for(auto p:b){if(p.first){cout<<"["<<p.first<<","<<p.second<<"], ";}}cout<<endl;
    
    ll cnt=0;
    if(b[0].first<n/2){
        cnt=(n/2-b[0].first)+(n/2-b[1].first);
    }else{
        cnt=n/2-b[1].first;
    }
    cout<<cnt<<endl;

    return 0;
}
