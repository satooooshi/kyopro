// C - A x B + C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;

int main(){
    
    ll n;
    cin>>n;
    ll cnt=0;
    for(ll a=1;a<=n;a++){
        for(ll b=1;b<=n/a;b++){
            if(n-a*b>0){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}