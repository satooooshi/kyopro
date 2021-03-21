// C - Anti-Division
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// gcd, lcm
// a と b の最大公約数を返す関数
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// bennzu

int main(){

    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a==b){
        if(a%c==0||a%d==0){
            cout<<0<<endl;
            return 0;
        }
    }

    if(c==d){
        cout<<(b-a)-(b/c-(a-1)/c)<<endl;
        return 0;
    }

    //cout<<(b-a+1)<<"-"<<(b/c-(a-1)/c)<<"-"<<(b/d-(a-1)/d)<<"+"<<b/lcm(c,d)<<endl;
    cout<<(b-a+1)-(b/c-(a-1)/c)-(b/d-(a-1)/d)+(b/lcm(c,d)-(a-1)/lcm(c,d))<<endl;

    return 0;
}

