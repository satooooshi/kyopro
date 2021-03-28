// C - Reconciled?
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod = 1000000007;

// buggy!!
int main(){

    ll n,m;
    cin>>n>>m;
    if(n<m)swap(n,m);
    // now n>=m
    if(n-m>1){
        cout<<0<<endl;
        return 0;
    }

    ll res=1;
    for(ll i=1;i<=m;i++){
        res=res*i%mod;
        res=res*i%mod;
        //if(res)cout<<res<<endl;
    }
    if(n==m){// 2n!m!
        cout<<2*res%mod<<endl;
    }else{ // n-m==1, n!m!
        cout<<res*n%mod<<endl;
    }
    


    return 0;
}


/*
int main() {
   ll n, m, ans = 1;
   cin >> n >> m;
 
   // 差が2以上だと、不可能なので
   if (abs(n - m) > 1) {
     cout << 0 << endl;
     return 0;
   }
 
   for (int i = 1; i <= n; i++) ans = ans * i % mod;
   for (int i = 1; i <= m; i++) ans = ans * i % mod;
   cout << ans * ((n == m) + 1) % mod << endl;
 }
*/