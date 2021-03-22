// C - Go Home
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

        ll x;
        cin>>x;
        for(int t=1;t<=x;t++){
            ll left=t*(1+t)/2;
            //cout<<t<<endl;
            if(left>=x){
                cout<<t<<endl;
                return 0;
            }
        }


    return 0;
}
