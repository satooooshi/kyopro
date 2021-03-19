#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int r,g,b,n;
    cin>>r>>g>>b>>n;

    ll cnt=0;
    for(int i=0;i<=n;i+=r){
        for(int j=0;j<=n-i;j+=g){
            if((n-i-j)%b==0){
                cnt++;
            }
            /* TLE
            for(int k=0;k<=n-i-j;k+=b){
                if(i+j+k==n){
                    cnt++;
                    //cout<<"R"<<i/r<<",G"<<j/g<<",B"<<k/b<<endl;
                }
            }
            */
        }
    }

    cout<<cnt<<endl;

    return 0;
}