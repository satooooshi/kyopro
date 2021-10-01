#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>>a(n, vector<ll>(3));
    vector<vector<ll>>dp(n, vector<ll>(3,0)); // day ith(0-indexed), choose j@i, kubaruDP, saikai/saishouDP
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <3; j++) {
            cin >> a[i][j];
        }
    } 
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];
    for (int i = 0; i < n-1; i++) { 
        for (int j = 0; j <3; j++) { 
            dp[i+1][(j+1)%3] = max(dp[i+1][(j+1)%3], dp[i][j]+a[i+1][(j+1)%3]);
            dp[i+1][(j+2)%3] = max(dp[i+1][(j+2)%3], dp[i][j]+a[i+1][(j+2)%3]);
        }
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;
    return 0;
}