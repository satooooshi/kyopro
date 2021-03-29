// B - Sum of Three Integers 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int k,s;
    cin>>k>>s;
    ll cnt=0;
    for(int x=0;x<=k;x++){
        for(int y=0;y<=k;y++){
            int z=s-x-y;
            if(0<=z&&z<=k){
                //cout<<x<<"+"<<y<<"+"<<z<<"="<<x+y+z<<endl;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}
