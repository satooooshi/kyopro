// C - X: Yet Another Die Game  / 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    ll x;
    cin>>x;
    ll r=x%11; // 5+6+5+6..
    ll plus=0;

    if(x<=6){ // 6+5+6+5..
        cout<<1<<endl;
        return 0;
    }

    if(r>6){ // need another 5+6
        plus=2;
    }else if(0<r&&r<=6){ // need another 5
        plus=1;
    }else{ // r==0
        plus=0;
    }

    //cout<<"x/11:"<<x/11<<", x%11:"<<x%11<<endl;

    cout<<x/11*2+plus<<endl;

    return 0;
}
