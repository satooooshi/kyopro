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

int H, W, N, A[101010], B[101010];
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> H >> W >> N;
    rep(i, 0, N) cin >> A[i] >> B[i];

    vector<int> ys;
    rep(i, 0, N) ys.push_back(A[i]);
    sort(all(ys));
    ys.erase(unique(all(ys)), ys.end());
    rep(i, 0, N) A[i] = lower_bound(all(ys), A[i]) - ys.begin();

    vector<int> xs;
    rep(i, 0, N) xs.push_back(B[i]);
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    rep(i, 0, N) B[i] = lower_bound(all(xs), B[i]) - xs.begin();

    rep(i, 0, N) printf("%d %d\n", A[i] + 1, B[i] + 1);

    return 0;
}