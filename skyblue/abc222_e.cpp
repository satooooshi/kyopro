#include <bits/stdc++.h>
using namespace std;

// dfs, recur, backtrack

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int N, M, K, A[101];
vector<pair<int, int>> E[1010];
int cnt[1010];
int dp[2][201010];
const int BASE = 100005;
//---------------------------------------------------------------------------------------------------
bool dfs(int cu, int pa, int goal) {
    if (cu == goal) return true;

    fore(p, E[cu]) if (p.first != pa) {
        bool res = dfs(p.first, cu, goal);
        if (res) {
            //Bに到達した後に再帰から戻ってくる帰りの部分は
            //丁度最短経路のみ通ってくることになる
            cnt[p.second]++;
            return true;
        }
    }

    return false;
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N >> M >> K;
    rep(i, 0, M) cin >> A[i];
    rep(i, 0, N - 1) {
        int u, v; cin >> u >> v;
        E[u].push_back({ v, i });
        E[v].push_back({ u, i });
    }

    rep(i, 0, M - 1) dfs(A[i], -1, A[i + 1]);
    for(int i=0;i<N-1;i++)cout<<cnt[i]<<endl;

    return 0;
}