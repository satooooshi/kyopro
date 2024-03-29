// C - Sqrt Inequality
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    ll a,b,c;
    cin>>a>>b>>c;

    if(c-a-b<=0){
        cout<<"No"<<endl;
        return 0;
    }

    ll right=4*a*b;
    ll left=(c-a-b)*(c-a-b);
    if(right>=left){
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;


    return 0;
}

