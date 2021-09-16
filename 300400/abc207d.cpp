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

int N, A[2010], B[2010];
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N;
    rep(i, 0, N) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) A[i] = l * 2, B[i] = r * 2 + 1;
        else if (t == 2) A[i] = l * 2, B[i] = r * 2;
        else if (t == 3) A[i] = l * 2 + 1, B[i] = r * 2 + 1;
        else A[i] = l * 2 + 1, B[i] = r * 2;
    }

    int ans = 0;
    rep(i, 0, N) rep(j, i + 1, N) {
        int AA = max(A[i], A[j]);
        int BB = min(B[i], B[j]);
        if (AA < BB) ans++;
    }
    cout << ans << endl;

    return 0;
}