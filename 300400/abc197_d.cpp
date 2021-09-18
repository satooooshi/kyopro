#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

//https://yamakasa.net/atcoder-abc-197-d/
int main() {
    int N;
    cin >> N;
    double x, y, X, Y;
    cin >> x >> y >> X >> Y;
    double dx = X - x;
    double dy = Y - y;
    double PI=acos(-1);
    double th=2*PI/N;
    double x0 = x - (x + X) / 2;
    double y0 = y - (y + Y) / 2;
    double x1 = cos(th) * x0 - sin(th) * y0;
    double y1 = sin(th) * x0 + cos(th) * y0;
    cout << fixed << setprecision(11);
    cout << x1 + (x + X) / 2 << " " << y1 + (y + Y) / 2 << "\n";
    return 0;
}
