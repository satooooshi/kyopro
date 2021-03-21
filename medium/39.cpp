// C - When I hit my pocket...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll k,a,b;
    cin>>k>>a>>b;

    if(b-a<=2){ // hit all
        cout<<k+1<<endl;
        return 0;
    }

    ll r=k-(a-1)-((k-(a-1))/2)*2;
    cout<<a+(b-a)*((k-(a-1))/2)+((r>0)?1:0)<<endl;


    return 0;
}
