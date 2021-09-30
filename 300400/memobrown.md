g++-10
./a.out < ~/Downloads/test_11.txt

#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int main() {
    string s,t;
    cin>>s>>t;
    if(s<t)cout<<"Yes"<<endl;
    else cout<<"no"<<endl;

    return 0;
}


```cpp
// int, 32bits(msb is signed bit), 2^30,10^9
// long, 64bits(..),2^60,10^18
```




casting 小数点以下が切り捨て
```cpp
    int a,b;
    cin>>a>>b;
    double c=(a-b)/3.0+b;
    //double c=(double)(a-b)/3+b;
    cout<<c<<endl;

    // 小数点での計算を排除
    included=108*n/100;

    // explicit casting vs. implicit casting
    cout << A * B / 100.0 << '\n';
    cout << ((double) (A * B)) / 100 << '\n';

    //1.21925e+07 と出力されてしまいます。std::fixed や std::setprecision を用いることで正確な表記になります。
    cout << fixed << setprecision(2);
    cout << A * B / 100.0 << '\n';

```

```cpp
// for-loop upper limit, answer upper limit、答えの上限を見積もることは非常に重要です

B-Savings
https://atcoder.jp/contests/abc206/editorial/2095
1000 日目以降は少なくとも毎日 1000 円以上貯金額が増え続けることが分かります。なので、このペースで 10^9円に到達するのは、どれだけ遅くとも 10^6+1000 (== 10^6) 日後であることがわかります。(10^6 * 10^3 == 10^9) (1000yen * 10^6niti --> over 10^9 yen in total at te end )


A+Bx≤D×Cx を満たすには
⇔A/(CD−B) ≤ x　　つまりxがこれ以上（xが最小１：cdーb＝＝Aからxが最大A以下CDーb＝＝１）である時に満たれ始めるA/(CD−B) ＝＝ x(そのような x の最小値)！！
明らかに、CD−B が非正であるなら高橋くんの目標は達成されません。そうでない場合、x は  
CD−B / A
​の切り上げとなります。CD−B は正整数ですから、x の値は A 以下となります。

故に必要な操作回数の最小値が A 以下になることが示されました。このように、答えの上限を見積もることは非常に重要です。
```
https://atcoder.jp/contests/abc211/editorial/2285

主客転倒）
UnionFind
今回の問題はすべての頂点間に対する処理になるので、すべての頂点間の列挙だけでO(n2)となる。
愚直にやっていくと、

すべての頂点間の組み合わせについて f(i,j) の総和

が答えになる。
だが、ここで役立つ条件としてf(i,j)は重みの種類だけパターンがある。
つまり、f(i,j)を全探索することは可能であるということである。
https://blog.hamayanhamayan.com/entry/2021/08/15/034729


配列「全体に何かする」という問題は割と出るクエリ問題であり、その場合にoffset的なものを使って高速化する
Querying Multiset [AtCoder Beginner Contest 212 D]


while( state of next op is satisfied ?? ex. cnt*2<n)
https://atcoder.jp/contests/abc216/tasks/abc216_c

216c many balls 後退解析風

topological sort to neighbot vector
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;
/* topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号
    計算量: O(|E|+|V|)
 */
vector<int> topo_sort(const Graph &G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e.to]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e.to]--;
            if (ind[e.to] == 0) {
                que.push(e.to);
            }
        }
    }
    return ans;
}

int main() {
    int n,m;cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int k,pre = -1;cin >> k;
        for (int j = 0; j < k; j++) {
            int a;cin >> a;a--;
            if (pre != -1) g[pre][a];//g.add_edge(pre,a);
            if (pre == a) { // exist loop, cannot sorttopologically
                puts("No");
                return 0;
            }
            pre = a;
        }
    }


    auto v = topo_sort(g);
    if (v.size() == n) puts("Yes");
    else puts("No");
    return 0;
}
```



map is automatically ordered by its key (left-side )
https://cpprefjp.github.io/reference/map/map/begin.html
```cpp
int main()
{
  map<int, char> m;
  for( auto i = m.begin(); i != m.end() ; ++i ) {
      std::cout << i->first << " " << i->second << "\n";
  }

  return 0;
}
```


```cpp
// culmulative sum cusum
int main(){
    int n; cin >> n; // 配列サイズ
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i]; // a の入力

    // 累積和 
    // cusum
    vector<int> s(n+1, 0); // s[0] = 0 になる
    for (int i = 0; i < n; ++i) s[i+1] = s[i] + a[i];

    ll res=-1;
    int k=4;// sum of 4 elements, i<n+1 !!!
    for(int i=k;i<n+1;i++){
        cout<<"["<<i-k<<","<<i<<"):"<<s[i]-s[i-k]<<endl;
        res=max(res,s[i]-s[i-k]);
    }

    // 区間 [left, right) の総和を求める
    int left, right;
    cin >> left >> right;
    cout << s[right] - s[left] << endl;

    return 0;
}
```


```cpp
// zaatu
// https://algo-logic.info/coordinate-compress/

// 1d
#include <bits/stdc++.h>
using namespace std;
/* compress
    X を座標圧縮して書き換える（副作用）
    返り値: ソート済みの値
    計算量: O(n log n)
*/
template <typename T>
vector<T> compress(vector<T> &X) {
    // ソートした結果を vals に
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    // 各要素ごとに二分探索で位置を求める
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}


//2d
/* compress
    (X1,Y1),(X2,Y2)という二点で表されるもの（長方形や直線など）について、行か列の片方（X1とX2 or Y1とY2）を座標圧縮する（副作用）
    返り値: ソートされ重複要素を除いた値
    計算量: O(n log n)
*/
template <typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2) {
    vector<T> vals;
    int N = (int)C1.size();
    for (int i = 0; i < N; i++) {
        for (T d = 0; d < 1; d++) {  // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    // ソート
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < N; i++) {
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}

int main() {
    // 入力
    int N;
    cin >> N;
    vector<long long> X1(N), Y1(N), X2(N), Y2(N);
    for (int i = 0; i < N; i++) {
        cin >> X1.at(i) >> Y1.at(i) >> X2.at(i) >> Y2.at(i);
    }
    // 座標圧縮
    vector<long long> X = compress(X1, X2);
    vector<long long> Y = compress(Y1, Y2);

    return 0;
}


// 2d ver2.
// ex. 
// Ai 4 1 9
// ys 1 4 9
// A[i] = lower_bound(all(ys), A[i]) - ys.begin();
// Ai 1 0 2
// C - Reorder Cards
// https://atcoder.jp/contests/abc213/tasks/abc213_c
int H, W, N, A[101010], B[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> H >> W >> N;
    rep(i, 0, N) cin >> A[i] >> B[i];

    vector<int> ys;
    rep(i, 0, N) ys.push_back(A[i]);
    sort(all(ys));
    ys.erase(unique(all(ys)), ys.end());
    rep(i, 0, N) A[i] = lower_bound(all(ys), A[i]) - ys.begin();

    vector<int> xs;
    rep(i, 0, N) xs.push_back(B[i]);
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    rep(i, 0, N) B[i] = lower_bound(all(xs), B[i]) - xs.begin();

    rep(i, 0, N) printf("%d %d\n", A[i] + 1, B[i] + 1);
}
```


```cpp
// union-find, kaibun index

// union-find, union find
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
int main() {
    int N, A[201010]; // 2*10^5 == 201010
	cin >> N;
	rep(i, 0, N) cin >> A[i];
 
	UnionFind uf(201010); // node numbers be in [0,201010)
	rep(i, 0, N / 2) uf(A[i], A[N - 1 - i]);
 
	int ans = 0;
	rep(i, 0, 201010) if (uf[i] == i) ans += uf.getValues(i) - 1;
	cout << ans << endl;
    return 0;
}


// union find simple ver.
// node numbers should be 0-indexed 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct UnionFind {
	//自身が親であれば、その集合に属する頂点数に-1を掛けたもの
	//そうでなければ親のid
	vector<int> r;
	UnionFind(int N) {
		r = vector<int>(N, -1);
	}
	int root(int x) {
		if (r[x] < 0) return x;
		return r[x] = root(r[x]);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}
	int size(int x) {
		return -r[root(x)];
	}
};
int main() {
	int N, M;
	cin >> N >> M;
	
	//友達集合を作る
	UnionFind UF(N);
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		A -= 1; B -= 1;
		UF.unite(A, B);
	}
	//最大の友達集合を求める
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, UF.size(i));
	}
	cout << ans << endl;
}

```


```cpp
priority_queue<int>q; // desc
priority_queue<int, vector<int>, greater<int> >q; // ascending order

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
min_priority_queue<ll> que;

```

```cpp

// imos O(x-axis length) vs. 包含 O(n^6)

//imos, overlappingの個数を数える　
for (int i = 0; i < T; i++) table[i] = 0;
for (int i = 0; i < C; i++) {
  table[S[i]]++;  // 入店処理: カウントを 1 増やす
  table[E[i]]--;  // 出店処理: カウントを 1 減らす
}
// シミュレート
for (int i = 0; i < T; i++) {
  if (0 < i) table[i] += table[i - 1];
}
// 最大値を調べる
M = 0;
for (int i = 0; i < T; i++) {
  if (M < table[i]) M = table[i];
}

//包含, overlappingの区間数を数える->es
        int AA = max(A[i], A[j]);
        int BB = min(B[i], B[j]);
        if (AA < BB) ans++;
包含しているならカウントしていけばいい。
[a,b)と[c,d)を合成した区間は[max(a,c), min(b,d))となるので、このルールで合成して、要素が存在する、つまり、if(max(a,c)< min(b,d)) , or if(!(r[i]<=l[j] or r[j]<=l[i]))



```cpp
// lower_bound after sorting by asc, 
//sentinel, auto idx =lower_bound() - a.begin()
// auto idx=lower_bound(dp.begin(),dp.end(),x)-dp.begin();

// abc212C - Min Difference
int main() {

    int n,m;cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int j=0;j<m;j++)cin>>b[j];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll res=infl;
    for(int i=0;i<n;i++){
        auto idx=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        if(idx<m){
            res=min(res,(ll)abs(a[i]-b[idx]));
        }
        if(idx-1>=0){
            res=min(res,(ll)abs(a[i]-b[idx-1]));
        }
    }

    cout<<res<<endl;

    

    return 0;
}
```


```cpp
// bfs,queue, bq, when edge weight==1, can find shortest path, 
// node# 0-indexed 

using namespace std;
using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}


// bfs ver.2 algo-logic
// https://algo-logic.info/bfs/
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
    int V, E;
    cin >> V >> E;
    int s, t;
    cin >> s >> t;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back({b});
        // G[b].push_back({a});
    }
    vector<bool> seen(V, false);  // 既に見たことがある頂点か記録する
    queue<int> que;
    que.emplace(s);  // sから探索する
    seen[s] = true;
    while (que.size() != 0) {     // 幅優先探索
        int state = que.front();  // 現在の状態
        que.pop();
        for (auto next : G[state]) {
            if (!seen[next]) {  // 未探索の時のみ行う
                seen[next] = true;
                que.emplace(next);  //次の状態をqueueへ格納
            }
        }
    }
    if (seen[t]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}

```

```cpp
//dfs, 隣接vector(頂点数多くて、変数が比較的少ない時)・再帰関数
// ATTENTION!! node# 0-indexed

#include <bits/stdc++.h>
using namespace std;

// 深さ優先探索 dfs
using Graph = vector<vector<int>>;
vector<bool> seen;  // 既に見たことがある頂点か記録
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next : G[v]) {
        if (!seen[next]) {  // 訪問済みでなければ探索
            dfs(G, next);
        }
    }
    //res.push_back(v); // pushes from leaf to the root
}
int main() {
    int V, E;
    cin >> V >> E;
    int s, t;
    cin >> s >> t;
    Graph G(V);//0-indexed
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back({b});
        // G[b].push_back({a});
    }
    seen.assign(V, false);  // 初期化
    dfs(G, s);
    if (seen[t]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
```

// vector matrix init
vector<vector<int>>dp(n+1,vector<int>(n+1,0));



```cpp
// gas stop 

int main() {

    int n,k;
    cin>>n>>k;
    map<ll,ll>m;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        m[a]+=b;
    }


    ll res=k;
    for(auto i = m.begin(); i != m.end() ; ++i ) {
        if(res<i->first){
            break;
        }else{
            res+=i->second;
        }
    }
    cout<<res<<endl;

    return 0;
}
```

```cpp
// cusum 2d ver.1
// クエリ [x1, x2) × [y1, y2) の半開区間長方形区域の和
// https://qiita.com/drken/items/56a6b68edef8fc605821
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力: H × W のグリッド
    int H, W; cin >> H >> W;
    vector<vector<int> > a(H, vector<int>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> a[i][j];

    // 二次元累積和
    vector<vector<int> > s(H+1, vector<int>(W+1, 0));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    // クエリ [x1, x2) × [y1, y2) の長方形区域の和
    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        // 長方形の足し引き (包除原理) 
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
    }
}   

// cusum 2d ver.2
// クエリ [sx, tx] × [sy, ty] の長方形区域の和
// [sx,sy]-[tx,ty], 閉区間[(sx,sy),(tx,ty))
//https://atcoder.jp/contests/abc203/submissions/23075536
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
    // クエリ [sx, tx] × [sy, ty] の長方形区域の和
    // [sx,sy]-[tx,ty], 半開区間[(sx,sy),(tx,ty))
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
//---------------------------------------------------------------------------------------------------
```


```cpp
// DP pattern 

dpi,j=now on ith, using some till ith, sum is j, コイン問題と同じ
D - Cooking 配るDP


```


sort by desc 
std::sort(v.begin(), v.end(), std::greater<int>() );




```cpp
// abc200
// mod 1, ai%200==x, aj%200==x then (ai-aj)%200==0
// mod 2, 0<=ai%200<200
// mod 3, n==8 ai modifications (256pattern in total) are assigned to 200 rooms at most, some of which contains more than two. ->  鳩の巣原理
// UF or map, nC2==Sigma[i:1,n-1]i==n(n-1)/2==[0,n-1]の和
```

//bitDP
cout<<bitset<8>(one)<<" "<<bitset<8>(two)<<endl;

(a^i)==b

O(n!) == n==10（3628800）が限度


```cpp
// warshall-floyd
// https://dai1741.github.io/maximum-algo-2012/docs/shortest-path/
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

const int INF = inf;
typedef vector<vector<int> > Matrix;

const int INF = 100000000;
Matrix d; // グラフの距離を格納した2次元配列（隣接行列）
          // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）

void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main() {
  int n, m;
  cin >> n;

  d = Matrix(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++) d[i][i] = 0;
  
  cin >> m;
  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    d[from][to] = cost;
  }
  
  warshall_floyd(n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && d[i][j] != INF)
        cout << i << "から" << j << "へのコスト: " << d[i][j] << endl;
    }
  }
  
  return 0;
}
```


B - Palindrome with leading zeros
0≤N≤10^9 meaning 10 digits at most
add at most 10 zeros to the front


割り算無くす-->掛け算の形に
(d-d/r)>0 torelence
-->
d*r-d>0



```cpp

// grid traverse
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};
const long long INF = 1LL<<60;
int H, W;
vector<string> fi;

long long solve() {
    vector<vector<long long>> dp(H, vector<long long>(W, INF));
    if(fi[0][0]=='#')dp[0][0]=1;
    else dp[0][0]=0;

    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            for(int i=0;i<2;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if (ny<0 || ny>= H || nx<0 || nx>=W)continue;
                int add = 0;
                if (fi[ny][nx] == '#' && fi[y][x] == '.')add=1;
                chmin(dp[ny][nx], dp[y][x] + add);
            }
        }
    }
    return dp[H-1][W-1];
}

int main() {
    cin >> H >> W;
    fi.resize(H);
    for (int i = 0; i < H; ++i) cin >> fi[i];
    cout << solve() << endl;
}

// depth-first grid traverse
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



int main() {
    int h,w,x,y;
    cin>>h>>w>>y>>x;// 0-indexed
    x--;
    y--;
    vector<string>g;
    for(int i=0;i<h;i++){
        string s;cin>>s;
        g.push_back(s);
    }

    // depth-first grid traverse
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {-1, 0, 1, 0};
    ll ans=1;
    for(int i=0;i<4;i++){
        int cx=x,cy=y;
        while(1){
            cx+=dx[i];
            cy+=dy[i];
            if(cx<0||cx>=w||cy<0||cy>=h)break;
            if(g[cy][cx]=='#')break;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}



```


nC2==Sigma[i:1,n-1]==n(n-1)/2
https://atcoder.jp/contests/abc197/editorial/997
N 要素の数列を 1 つ以上の空でない連続した区間に分ける方法を全て試すには、隣り合う要素の間 (N−1 個ある) それぞれに仕切りを入れるか入れないかの 2^(N−1)通りを試せばよいです。 --> bitDP
// 余事象 abc195_c  C-comma

#include<bits/stdc++.h>
using namespace std;

// 余事象
int main() {
    ll n;cin>>n;
    ll ans=0;
    if (n>=1000) ans+=n-999;
    if (n>=1000000) ans+=n-999999;
    if (n>=1000000000) ans+=n-999999999;
    if (n>=1000000000000) ans+=n-999999999999;
    if (n>=1000000000000000) ans+=n-999999999999999;
    cout<<ans<<endl;

    return 0;
}


```cpp
// nCr
// C - Duodecim Ferra
// https://yamakasa.net/atcoder-abc-185-c/
#include <stdio.h>
typedef long long ll;
ll _nCr(ll n, ll r){ 
   if( n<r || n<0 || r<0 ){ return 0; } 
   ll ans=1; if(r>(n-r)){ r=n-r; } 
   for(ll i=1;i<=r;i++){ ans*=(n+1-i); ans/=i; } 
   return ans; 
}
 
int main(){
   ll i,n,k=12,ans=0;
   scanf("%lld",&n);
   printf("%lld\n",_nCr(n-1,k-1));
   return 0;
}
```


put sentinels to vector, lower_bound

C - Repsept
https://atcoder.jp/contests/abc174/tasks/abc174_c
// Aiの中にKの倍数 --> Ai≡0 mod K, mod Kの値は[0,k)で循環


```cpp
// enum_divisors(約数s)
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main() {
    long long N;
    cin >> N;
    const auto &res = enum_divisors(N);
    for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
}

// prime_factorize
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    long long N;
    cin >> N;
    const auto &res = prime_factorize(N);
    cout << N << ":";
    for (auto p : res) {
        for (int i = 0; i < p.second; ++i) cout << " " << p.first;
    }
    cout << endl;
}
```

ある素数 p と正の整数 e を用いて、 z=p^eと表せる  つまりzは約数(divisor)



```cpp
// D - String Formation
#include <bits/stdc++.h>
// c++などで普通の文字列型の先頭に追加する操作は
// 計算量が悪いため、dequeue
#include <deque> 
 
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
 
int main(){
 
    string s;
    int n;
    cin>>s>>n;
    deque<char>dq;
    for(int i=0;i<s.length();i++){
        dq.push_back(s[i]);
    }
    int r=0;
    rep(i,n){
        int q;
        cin>>q;
        if(q==1)r=1-r;
        else if(q==2){
            int f;
            char c;
            cin>>f>>c;
            if(r)f=3-f;
            if(f==1)dq.push_front(c);
            else dq.push_back(c);
        }
        //cout<<s<<endl;
    }
    /*
    if(r){
        for(int i=dq.size()-1;i>=0;i--)cout<<dq[i];
    }else{
        for(int i=0;i<dq.size();i++)cout<<dq[i];
    }
    cout<<endl;
    */
    //
    if (r) reverse(dq.begin(), dq.end());
    for (auto c : dq) cout << c;
    cout<<endl;
 
 
 
    return 0;
}
```

// implicit casting
e[i]=1.0*(1+p)/2;



```cpp
// 期待値
// E[X+Y] == E[X]+E[Y] 線形性
// next_permutation o(n!) max n==10
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
    int n;cin>>n;
    vector<int>a(n);
    map<vector<int>,int>ord;
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    vector<int>p(n),q(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>q[i];
    }


    int i=0;
    do{
        ord[a]=i++;
    }while(next_permutation(a.begin(),a.end()));

    cout<<abs(ord[p]-ord[q])<<endl;
    return 0;
}

```



```cpp
//binary search,bs, O(log2N)

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll a,b,x;
bool check(ll n) {
    ll dn = to_string(n).length();
    return (a*n+b*dn)<=x;
}

int main() {
    cin >> a >> b >> x;
    ll left = 0, right = 1000000001;
    ll ans=left;
    while ( right - left > 1 ) {
        ll mid = (left + right) / 2;
        if (check(mid)){
            left=mid;
            ans=mid;
        }else{
            right=mid;
        } 
    }
    cout << ans << endl;
    return 0;
}
```


ll digit_num(ll x){
    return to_string(x).length();
}


二項定理



```cpp
//angle is double !!
int degree;// do
double PI = acos(-1);  // PI = 3.141593...
double rad = deg * PI / 180.0;// degree -> radian
double ans=cos(rad);

// D water bottle, binary search with floating point O(log2N) kai loop
//https://atcoder.jp/contests/abc144/tasks/abc144_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

// f(a,b,theta):=の時の入る水の容量の最大値
// bs

double PI = acos(-1);  // PI = 3.141593...
int a,b,x;
bool check(long double deg) {
    if(a*a*b>=2*x){
        long double rad=(90-deg)* PI / 180.0; // in radian
        return 1.0*b*b*a*tan(rad) >= 2.0*x;
    }else{
        long double rad=deg* PI / 180.0; // in radian
        return 1.0*(2*a*a*b-a*a*a*tan(rad)) >= 2.0*x;
    }
}

int main() {

    cin>>a>>b>>x;

    long double left=0,right=90; // [0do,90do) in degree
    long double ans=left; // in degree
    //while(right-left>1){
    for(int _ = 1; _ <= 100000; _++) {
        long double mid=(left+right)/2.0;// in degree
        if(check(mid)){
            left=mid;
            ans=mid;
        }else{
            right=mid;
        }

    }
    cout << fixed << setprecision(10);
    cout<<ans<<endl;
 
    return 0;
}

```


```cpp
// base number 進数
// #include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int main() {

    ll n;cin>>n;
    vector<char>c(27);// 1-indexed, c[0] has nothing
    for(int i=1;i<=26;i++){
        c[i]='a'+(i-1);
    }
    //for(auto e:c)cout<<e<<endl;

    // Base　26
    string res="";
    while(n>0){
        int d=n%26;
        if(d==0){
            d=26;
            n--;
        }
        res+=c[d];
        n/=26;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;

    return 0;
}

```

// mod, 合同式
// i ≡ 0 mod c 
// i%c==0

```cpp
// doubling dp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int main() {
    string S;
    cin >> S;
    int N = S.size();

    // 初期値を埋める、 (2^0, parent)先の遷移先
    vector<vector<int>> next(MAX, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'L') next[0][i] = i-1;
        else next[0][i] = i+1;
    }
    for (int d = 0; d+1 < MAX; ++d) {
        for (int i = 0; i < N; ++i) { // every nodes
            // ex. node 1から出発して、2^3先の遷移node。
            // d+1==3 d==2 i==2
            //nv:=next[2][1]=3- > next[2][nv=3]
            next[d+1][i] = next[d][next[d][i]];
        }
    }

    vector<int> res(N, 0);
    int K = N*2;
    for (int v = 0; v < N; ++v) {
        int nv = v;
        // ex. node 10の13(01101)先の遷移先
        for (int d = 0; d < MAX; ++d) {
            // traverse from lsb
            // nv:=next[....1][10]
            // nv:=next[..1..][nv]
            // nv:=next[.1...][nv]
            if (K & (1<<d)) nv = next[d][nv];
        }
        res[nv]++;
    }
    for (int v = 0; v < N; ++v) cout << res[v] << " ";
    cout << endl;
}

```






```cpp
// https://atcoder.jp/contests/abc136/tasks/abc136_d
// recDP
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int n;
vector<int>a;
vector<int>cnt(10,0);//K=0,1,…,9

void rec(int i, int j){
    if(i==n-1){
        cnt[j]++;
        return ;
    }

    rec( i+1, (a[i+1]+j)%10 );
    rec( i+1, (a[i+1]*j)%10 );

    return ;
}

int main() {

    cin>>n;
    a.resize(n);
    for(auto &e:a)cin>>e;

    // red(i,j):= (先頭 op a[i])%10==jし終わった時のi,j, recDP
    rec(0,a[0]);

    for(int i=0;i<10;i++){
        cout<<cnt[i]<<endl;
    }

    return 0;
}
```

```cpp
// count up 01(pivot)
int main(){
    int N;
    cin>>N;
    int h[N];
    for(int i=0;i<N;i++){
        cin>>h[i];
    }

    int c=0;
    while(1){
        int zc=0;
        for(int i=0;i<N;i++){
            if(h[i]<=0) zc++;
            if(h[i]>0&&(i==0||h[i-1]<0)) c++;
            h[i]--;
        }
        if(zc==N) break;
    }
    cout<<c<<endl;
}

```