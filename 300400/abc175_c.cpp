#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    ll x,k,d;cin>>x>>k>>d;
     
    x=abs(x);
    // exeption
    if(k<x/d){cout<<abs(x-d*k)<<endl;return 0;}

    x-=(x/d)*d;
    k-=(x/d);

    if(k%2==0){
        cout<<abs(x)<<endl;
    }else{
        cout<<abs(x-d)<<endl;
    }

    return 0;
}
