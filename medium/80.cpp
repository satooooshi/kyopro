// A - Colorful Subsequence
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    ll n;
    string s;
    cin>>n>>s;
    vector<int>num(26,0);
    for(auto c:s){
        num[c-'a']++;
    }
    //for(auto x:num){cout<<x<<" ";}cout<<endl;

    ll res=1;
    for(auto x:num){
        res*=x+1;
        res%=mod;
    }
    // dont take account of null string
    cout<<(res-1+mod)%mod<<endl;


    return 0;
}