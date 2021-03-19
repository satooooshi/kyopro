// C - Dice and Coin
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n,k;
    cin>>n>>k;
    double res=0.0;
    for(int i=1;i<=n;i++){
        int a=i;
        double t=1.0/double(n);
        while(a<k){
            a=2*a;
            t/=2;
        }
        res+=t;
    }
    
    cout<< std::fixed << std::setprecision(12)<<res<<endl;
    return 0;
}