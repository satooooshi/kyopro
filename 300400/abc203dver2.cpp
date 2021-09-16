#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

 
int N, K, A[808][808];
//---------------------------------------------------------------------------------------------------
int check(int x) {
    // 入力: N × N のグリッド
    vector<vector<int> > b(N, vector<int>(N,0));
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) if(A[i][j]>=x) b[i][j]=1;

    // 2dcusum
    vector<vector<int> > s(N+1, vector<int>(N+1, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + b[i][j];

    // クエリ [j-K, j) × [i-K, i) の長方形区域の和
    for (int i = K; i <=N; ++i)
        for (int j = K; j <=N; ++j){
            ll cnt=s[i][j] - s[i-K][j] - s[i][j-K] + s[i-K][j-K];
            if (cnt < K * K / 2 + 1) return false;
        }
    
    return true;
}
//---------------------------------------------------------------------------------------------------
int main() {
	cin >> N >> K;
	rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];
 
	int ok = 0, ng = inf;
	while (ok + 1 != ng) {
		int md = (ok + ng) / 2;
		if (check(md)) ok = md;
		else ng = md;
	}
	cout << ok << endl;
    return 0;
}