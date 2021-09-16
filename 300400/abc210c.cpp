#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int N, K, c[301010];
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N >> K;
    rep(i, 0, N) cin >> c[i];

    map<int, int> cnt;
    int kinds = 0;
    int ans = 0;

    rep(i, 0, K) {
        if (cnt[c[i]] == 0) kinds++;
        cnt[c[i]]++;
    }
    chmax(ans, kinds);
    
    rep(i, K, N) {
        if (cnt[c[i - K]] == 1) kinds--;
        cnt[c[i - K]]--;
        if (cnt[c[i]] == 0) kinds++;
        cnt[c[i]]++;
        chmax(ans, kinds);
    }

    cout << ans << endl;

    return 0;
}