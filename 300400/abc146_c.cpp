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

ll a,b,x;
bool check(ll n) {
    ll dn = to_string(n).length();
    return (a*n+b*dn)<=x;
}

int main() {
    cin >> a >> b >> x;
    ll left = 0, right = 1000000001;
    ll ans=left;
    while ( right - left > 1 ) {
        ll mid = (left + right) / 2;
        if (check(mid)){
            left=mid;
            ans=mid;
        }else{
            right=mid;
        } 
    }
    cout << ans << endl;
    return 0;
}