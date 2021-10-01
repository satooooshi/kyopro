#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long infll = 1LL<<60; // 62-bit long, MSBit is reserved for  pos/neg bit.

int main() {
    string s,t;
    cin >> s >> t;
    vector<vector<ll>>dp(s.size()+1, vector<ll>(t.size()+1,0)); // maekara s,t chars made ikutukatukatta tokino saidai/saishouDP, morauDP,  
   
    for (int i = 1; i < s.size()+1; ++i) {
        for (int j = 1; j < t.size()+1; ++j) {
            if (s[i-1] == t[j-1]){
                chmax(dp[i][j], dp[i-1][j-1] + 1);
            }
            else
            {
                chmax(dp[i][j], dp[i][j-1]);
                chmax(dp[i][j], dp[i-1][j]);
            } 
            
        }
    }

    // 復元
    string res = "";
    int i = (int)s.size(), j = (int)t.size();
    while (i > 0 && j > 0)
    {
        // (i-1, j) -> (i, j) と更新されていた場合
        if (dp[i][j] == dp[i-1][j]) {
            --i; // DP の遷移を遡る
        }

        // (i, j-1) -> (i, j) と更新されていた場合
        else if (dp[i][j] == dp[i][j-1]) {
            --j; // DP の遷移を遡る
        }

        // (i-1, j-1) -> (i, j) と更新されていた場合
        else {
            res = s[i-1] + res; // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
            --i, --j; // DP の遷移を遡る
        }
    }
    cout << res << endl;
    return 0;
}