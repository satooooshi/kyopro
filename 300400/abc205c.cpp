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


ll A, B, C;
//---------------------------------------------------------------------------------------------------
ll pow(ll X, ll Y) {
    if (Y == 1) return X;
    return X * X;
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> A >> B >> C;

    if (C % 2 == 0) C = 2;
    else C = 1;

    if (pow(A, C) == pow(B, C)) cout << "=" << endl;
    else if (pow(A, C) < pow(B, C)) cout << "<" << endl;
    else cout << ">" << endl;
    return 0;
}