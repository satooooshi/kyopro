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
//---------------------------------------------------------------------------------------------------
struct Ruisekiwa2D {
    int VH, VW;
    using T = int;
    vector<vector<T>> v;
    bool needBuild = false;
    Ruisekiwa2D() { }
    Ruisekiwa2D(int w, int h) { init(w, h); }
    void init(int w, int h) {
        needBuild = true;
        VH = h; VW = w;
        v.clear();
        v.resize(h, vector<T>(w));
        rep(y, 0, VH) rep(x, 0, VW) v[y][x] = 0;
    }
    void set(int x, int y, T c) { v[y][x] = c; }
    void add(int x, int y, T c) { v[y][x] += c; }
    void build() {
        rep(y, 0, VH) rep(x, 0, VW) {
            if (0 < y) v[y][x] += v[y - 1][x];
            if (0 < x) v[y][x] += v[y][x - 1];
            if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
        }
        needBuild = false;
    }
    // [sx,sy]-[tx,ty]
    T get(int sx, int tx, int sy, int ty) {
        if (needBuild) assert(0 && "Need Build");
        if (tx < sx or ty < sy) return 0;
        T rs = v[ty][tx];
        if (0 < sx) rs -= v[ty][sx - 1];
        if (0 < sy) rs -= v[sy - 1][tx];
        if (0 < sx && 0 < sy) rs += v[sy - 1][sx - 1];
        return rs;
    }
};

 
int N, K, A[808][808];
//---------------------------------------------------------------------------------------------------
int check(int lim) {
    Ruisekiwa2D r2d(N, N);
    rep(y, 0, N) rep(x, 0, N) if (lim <= A[y][x]) r2d.add(x, y, 1);
    r2d.build();
 
    rep(y, 0, N - K + 1) rep(x, 0, N - K + 1) {
        int tot = r2d.get(x, x + K - 1, y, y + K - 1);
        if (tot < K * K / 2 + 1) return false;
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