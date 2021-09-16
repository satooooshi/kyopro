#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

//---------------------------------------------------------------------------------------------------
struct UnionFind {
	using T = int;
	const T def = 0;
	T f(T a, T b) { return a + b; }
	//==========================================
    vector<int> par; 
	vector<T> value;
    UnionFind() {}
    UnionFind(int NV) { init(NV); }
	void init(int NV) { par.clear(); rep(i, 0, NV) par.push_back(i); value.resize(NV, 1); }
    void reset() { rep(i, 0, par.size()) par[i] = i; }
	int operator[](int x) {
		if (par[x] == x) return x;
		else {
			int res = operator[](par[x]);
			if (res != par[x]) {
				value[res] = f(value[res], value[par[x]]);
				value[par[x]] = def;
			}
			return par[x] = res;
		}
	}
	// uf(x,y)->y
    void operator()(int x, int y) {
		x = operator[](x); y = operator[](y); 
		if (x != y) {
			value[y] += value[par[x]];
			value[par[x]] = def;
			par[x] = y;
		}
	}
	T getValues(int x) { return value[operator[](x)]; };
};
//---------------------------------------------------------------------------------------------------

int N;

int main() {
    cin >> N;
    vector<tuple<int, int, int>> edges;
    rep (i, 0, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({ w, u, v });
    }
    sort(all(edges));

    UnionFind uf(N);
    ll ans = 0;
    fore(edge, edges) {
        int u, v, w;
        tie(w, u, v) = edge;

        ans += 1LL * w * uf.getValues(u) * uf.getValues(v);
        uf(u, v);
    }
    cout << ans << endl;
}