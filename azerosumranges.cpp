#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // input
    ll N;
    cin >> N;
    vector<ll> A(N), S(N+1, 0);
    
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];  // 累積和
    }
    
    // calculate nC2
    ll res = 0;
    map<ll, ll> mp;
    for (ll i = 0; i < N+1; ++i) {
        res += mp[S[i]];  // key がなければ 0 を返す
        mp[S[i]]++;
    }
    
    cout << res << "\n";
    
    return 0;
}