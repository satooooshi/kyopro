#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    int w;
    cin >> n >> w;
    vector<vector<ll>>a(n+1, vector<ll>(2)); // 1-indexed
    vector<vector<ll>>dp(n+1, vector<ll>(w+1,0)); // goods ith(1-indexed), weight j@i, morauDP, saidai/saishouDP
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j<2; j++) {
            if(i==0)a[i][j]=0;
            else cin >> a[i][j];
        }
    } 

    for (int i = 1; i <n+1; i++) { 
        for (int j = 0; j <= w; j++) { 
            if(j-a[i][0]<0){
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i][0]]+a[i][1]);
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}