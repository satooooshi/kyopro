// C - Scc Puzzle
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,m;
    cin>>n>>m;
    ll cnt=0;
    /*TLE
    while(m-2>=0&&n-1>=0){
        m-=2;
        n-=1;
        cnt++;
    }
    cnt+=m/4;
    cout<<cnt<<endl;
    */

   if(2*n<=m){
       cnt+=n;
       m-=2*n;
       cnt+=m/4;
   }else{
       cnt+=m/2;
   }
   cout<<cnt<<endl;


    return 0;
}
