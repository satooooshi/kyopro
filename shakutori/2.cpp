#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;


// gcd, lcm
// a と b の最大公約数を返す関数
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main(){

    int a,b,n;
    cin>>a>>b>>n;

    int l=lcm(a,b);
    for(int i=n;;i++){
        if(i%l==0){
            cout<<i<<endl;
            return 0;
        }
    }


    return 0;
}