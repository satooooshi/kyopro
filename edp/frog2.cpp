#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll infll = 11234567890;

int main() {
    int n,k; cin >> n >> k;
    vector<long> h(n);
    for(int i = 0; i < n; i ++) cin >> h[i];
    vector<long> dp(n, infll); // i th (0-indexed) の足場（を含む）までのコストの最小値. 最大最小DP
    dp[0] = 0;
    for(int i = 1; i < n; i ++) {
        for(int j = 1; j <= k; j ++) {
            if(i-j>=0) dp[i] = min(dp[i],abs(h[i]-h[i-j]) + dp[i-j]);
        }
    }
    cout << dp[n-1] << endl;
}