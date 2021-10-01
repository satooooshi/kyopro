#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    int w;
    cin >> n >> w;
    ll vmax=n*1000*10;
    vector<vector<ll>>a(n+1, vector<ll>(2)); // 1-indexed, (w,v)
    vector<vector<ll>>dp(n+1, vector<ll>(vmax+1,w+1)); // goods ith(1-indexed), weight j@i, morauDP, saidai/saishouDP
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j<2; j++) {
            if(i==0)a[i][j]=0;
            else cin >> a[i][j];
        }
    } 

    dp[0][0]=0; // inf otherwise
    for (int i = 1; i <n+1; i++) { 
        for (int j = 0; j <= vmax; j++) { 
            dp[i][j] = dp[i-1][j];
            if(j-a[i][1]>=0){
                dp[i][j]=min(dp[i][j], dp[i-1][j-a[i][1]]+a[i][0]);
            }
        }
    }

    for(int j=vmax;j>0;j--)
	{
			if (dp[n][j]<= w)
			{
				cout << j << endl;
				return 0;
			}
	}
    return 0;
}