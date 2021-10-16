#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

 
 // https://blog.hamayanhamayan.com/entry/2021/03/14/002113
 
 
int N, M, Q, W[50], V[50], X[50];
int L, R;
//---------------------------------------------------------------------------------------------------
int solve() {
    atcoder::mcf_graph<int, ll> mcf(N + M + 2);
 
    int st = N + M;
    int gl = st + 1;
    int MAX = 1010101;
 
    rep(i, 0, N) mcf.add_edge(st, i, 1, 0);
    rep(i, 0, N) rep(j, 0, M) {
        if (L - 1 <= j && j <= R - 1) continue;
        mcf.add_edge(i, N + j, (W[i] <= X[j]), MAX - V[i]);// MAX - V[i] cost >=0 にするため！！
    }
    rep(j, 0, M) mcf.add_edge(N + j, gl, 1, 0);
 
    int flow;
    ll cost;
    tie(flow, cost) = mcf.flow(st, gl);
    return 1LL * MAX * flow - cost;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> Q;
	rep(i, 0, N) cin >> W[i] >> V[i];
	rep(i, 0, M) cin >> X[i];
	rep(_, 0, Q) {
		cin >> L >> R;
		cout << solve() << endl;
	}
}
 
 