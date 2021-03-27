// C - Otoshidama
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,y;
    cin>>n>>y;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int k=n-i-j;
            if(i*10000+j*5000+k*1000==y){
                cout<<i<<" "<<j<<" "<<k<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<" "<<-1<<" "<<-1<<endl;


    return 0;
}
