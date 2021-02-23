#include <bits/stdc++.h>
// ABC061_C
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main() {
    // input
    ll N, K, a, b, sum = 0, maxN = 100000 + 1;
    cin >> N >> K;
    vector<ll> num(maxN, 0);
    REP(i, N) {
        cin >> a >> b;
        num[a] += b;
    }

    // 各数が何個あるかの累積和を計算
    for (ll i = 0; i < maxN; ++i) {
        sum += num[i];
        if (K <= sum) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}