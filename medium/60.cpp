#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    map<char,int>m;
    rep(i,n){
        string s;
        cin>>s;
        m[s[0]]++;
    }
    
    // 5C3 == 10 combis
    vector<string>strs={"mar","mac","mah","mrc","mrh","arc","arh",
                    "rch","mch","ach"};

    //for(auto a:m)cout<<a.first<<" "<<a.second<<endl;
    ll cnt=0;
    for(string t:strs){
        cnt+=m[t[0]-32]*m[t[1]-32]*m[t[2]-32];
    }
    cout<<cnt<<endl;


    return 0;
}

