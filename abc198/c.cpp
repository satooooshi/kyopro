// https://yamakasa.net/atcoder-abc-198-c/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main() {
    ll R, X, Y;
    cin >> R >> X >> Y;
    double d = sqrt(X * X + Y * Y);
    ll l = floor(d);
    if (floor(d) == ceil(d) && l % R == 0) {
        cout << l / R << "\n";
    } else if (d < R) {
        cout << 2 << "\n";
    } else {
        cout << l / R + 1 << "\n";
    }
    return 0;
}