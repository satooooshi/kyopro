// A. ><
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    string s;
    cin>>s;
    vector<pair<ll,ll>>v;
    ll a=0, b=0;// #<s, #>s
    for(ll i=1;i<s.length();i++){
        if(s[i-1]=='>')b++;
        else a++;
        if(s[i-1]=='>'&&s[i]=='<'){
            //cout<<"#<s"<<a<<", #>s:"<<b<<endl;
            v.push_back({a,b});
            a=0;
            b=0;
        }
    }
    if(s[s.length()-1]=='>')b++;
    else a++;
    v.push_back({a,b});
    //cout<<"#<s"<<a<<", #>s:"<<b<<endl;

    ll res=0;
    for(auto p:v){
        ll a=p.first;
        ll b=p.second;
        chmax(a,b);
        //cout<<"SigmaA:"<<a*(1+a)/2<<", SigmaB:"<<b*(b-1)/2<<endl;
        res+=a*(1+a)/2+b*(b-1)/2;
    }
    cout<<res<<endl;
    



    return 0;
}


