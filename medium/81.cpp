// C. 一次元リバーシ / 1D Reversi

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    string s;
    cin>>s;

    ll cnt=0;
    for(int i=1;i<s.length();i++){
        if(s[i-1]!=s[i])cnt++;
    }
    cout<<cnt<<endl;


    return 0;
}
