#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long infll = 1LL<<60; // 62-bit long, MSBit is reserved for  pos/neg bit.
const ll mod=1000000000+7;

int main() {
    int h, w; 
    string a[1010]; // h,w <= 1000, need some gaps...
    ll dp[1010][1010]; // kazoeage, morauDP

    cin >> h >> w;
    for(int i=0;i<h;i++){
        cin>>a[i];
    }
 
    dp[0][0] = 1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i-1>=0 && a[i-1][j]!='#'){
                dp[i][j]+=dp[i-1][j]%mod;
            }
            if(j-1>=0 && a[i][j-1]!='#'){
                dp[i][j]+=dp[i][j-1]%mod;
            }
        }
    }
    cout << dp[h - 1][w - 1]%mod << endl;
    return 0;
}