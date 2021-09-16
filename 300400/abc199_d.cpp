#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

// union-find
//---------------------------------------------------------------------------------------------------
struct UnionFind {
	using T = int;
	const T def = 0;
	T f(T a, T b) { return a + b; }
	//==========================================
    vector<int> par; 
	vector<T> value;
    UnionFind() {}
    UnionFind(int NV) { init(NV); }// #nodes NV, and node numbers be in [0,NV)
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
    // # nodes connected in this union
	T getValues(int x) { return value[operator[](x)]; };

};
//---------------------------------------------------------------------------------------------------



// 深さ優先探索 dfs
using Graph = vector<vector<int>>;
vector<bool> seen;  // 既に見たことがある頂点か記録
vector<int>color(100,-1);// -1 not colored yet
void dfs(const Graph &G, int v, vector<int> &res) {
    seen[v] = true;
    res.push_back(v);
    for (auto next : G[v]) {
        if (!seen[next]) {  // 訪問済みでなければ探索
            dfs(G, next, res);
        }
    }
    
}

ll rec(const Graph &G, int i, vector<int> &vec){
    if(i==vec.size())return 1;// 0-indexed
    int v=vec[i];

    vector<int>cnt(3,0);//cnt of neighbor colors
    for(auto nv : G[v]){// nv including v's parent
        if(color[nv]!=-1){
            cnt[color[nv]]++;
        }
    }

    // exhaustive search
    ll res=0;
    for(int c=0;c<3;c++){//red,green,blue
        if(cnt[c]==0){
            color[v]=c;
            res+=rec(G,i+1,vec);
            color[v]=-1;
        }
    }
    return res;
}

int main() {
    int V, E;
    cin >> V >> E;
    Graph G(V);
    seen.assign(V, false);  // 初期化
    UnionFind uf(V); // node numbers be in [0,V)
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back({b});
        G[b].push_back({a});
        uf(a,b);
    }
    map<int,int>m;
    for(int i=0;i<V;i++){
        m[uf[i]]++;
    }
    ll ans=1;
    vector<vector<int>>results;
    for(auto it=m.begin();it!=m.end();it++){
        vector<int>res;// reverse order of visiting nodes
        dfs(G,it->first,res);
        ans*=rec(G,0,res);
        //results.push_back(res);
        //cout<<"parent:"<<it->first<<endl;
        //for(auto e:res)cout<<e<<endl;
    }
    cout<<ans<<endl;

    return 0;
}