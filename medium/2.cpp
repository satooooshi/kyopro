// A - Irreversible operation
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    string s;
    cin>>s;
    vector<ll>b(s.length());
    if(s[0]=='B')b[0]=1;
    else b[0]=0;
    ll cnt=0;
    for(int i=1;i<s.length();i++){
        if(s[i]=='B')b[i]=b[i-1]+1;
        else{
            b[i]=b[i-1];
            cnt+=b[i];
        } 
    }
    cout<<cnt<<endl;


    return 0;
}
