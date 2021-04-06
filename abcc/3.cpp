// C - Super Ryuma
// https://drken1215.hatenablog.com/entry/2020/11/22/224600
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    auto solve = [&]() -> long long {
        long long p = abs(c - a), q = abs(d - b);
        if (p == 0 && q == 0) return 0;
        if (p == q || p + q <= 3) return 1;
        if ((p + q) % 2 == 0 || p + q <= 6 || abs(p - q) <= 3) return 2;
        return 3; 
    };
    cout << solve() << endl;
}