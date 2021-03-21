#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){


    return 0;
}




```cpp

// shakutorihou 尺取り法
/*
長さ nn の正の整数列 a1,a2,…,ana1,a2,…,an と整数 xx が与えられる。整数列の連続する部分列で、その総和が xx 以下となるものを数え上げよ (実際の出題は QQ 個のクエリがあって各クエリごとに xx が与えられる)。
*/
using namespace std;

int main() {
    /* 入力受け取り */
    int n, Q;
    cin >> n >> Q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    /* Q 回分のクエリを処理 */
    for (int j = 0; j < Q; ++j) {
        long long x; cin >> x; // 各クエリ x

        /* 合計値 */
        long long res = 0;

        /* 区間の左端 left で場合分け */
        int right = 0;     // 毎回 right を使い回すようにする
        long long sum = 0; // sum も使い回す
        for (int left = 0; left < n; ++left) {
            /* sum に a[right] を加えても大丈夫なら right を動かす */
            while (right < n && sum + a[right] <= x) {
                sum += a[right];
                ++right;
            }

            /* break した状態で right は条件を満たす最大 */
            res += (right - left);

            /* left をインクリメントする準備 */
            if (right == left) ++right; // right が left に重なったら right も動かす
            else sum -= a[left]; // left のみがインクリメントされるので sum から a[left] を引く
        }

        cout << res << endl;
    }
}

/*
長さ nn の正の整数列 a1,a2,…,ana1,a2,…,an と整数 xx が与えられる。整数列の連続する部分列で、その総和が xx 以上となるもののうち、最小の長さを求めよ (実際の出題は QQ 個のクエリがあって各クエリごとに xx が与えられ、条件を満たす区間がないときは 00 を出力)。
*/
using namespace std;

int main() {
    /* クエリ回数 */
    int Q;
    cin >> Q;

    for (int query = 0; query < Q; ++query) {
        /* 入力受け取り */
        int n; cin >> n;
        long long x; cin >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        /* 区間の長さの最小値 */
        int res = n+1; // 上界を入れておく

        /* 区間の左端 left で場合分け */
        int right = 0;
        long long sum = 0;
        for (int left = 0; left < n; ++left) {
            /* [left, right) の総和が x 以上となる最小の right を求める */
            while (right < n && sum < x) {
                sum += a[right];
                ++right;
            }

            /* 更新 */
            if (sum < x) break; // これ以上 left を進めてもダメ
            res = min(res, right - left);

            /* left をインクリメントする準備 */
            if (right == left) ++right; // right が left に重なったら right も動かす
            else sum -= a[left]; // left のみがインクリメントされるので sum から a[left] を引く
        }

        /* res = n+1 のときは解なし */
        if (res < n+1) cout << res << endl;
        else cout << 0 << endl;
    }
}

//bit
for(int bit=0;bit<(1<<n);bit++){
    bool ok=true;
    if ( y[i][j]==0 && (bit&(1<<)) ) ok=false;
    if(!(bit&(1<<)))
    if((~bit)&(1<<))
}

// ruisekiwa
//-------------------------------------------
int N; cin >> n; // 配列サイズ
vector<int> a(n);
for (int i = 0; i < n; ++i) cin >> a[i]; // a の入力

// 累積和
vector<int> s(n+1, 0); // s[0] = 0 になる
for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];
// print S
for (int i = 0; i < n+1; ++i) cout<<s[i]<<endl;

// Sigma A[a,b] == S[b+1]-S[a]
// Sigma A[left,right) == S[right]-S[left]

// 区間 [left, right) の総和を求める
int left, right;
cin >> left >> right;
cout << s[right] - s[left] << endl;

//--------------------------------------------
// character

    for(char c='a'; c<='z'; c++){
    
    }

    // c[n][l]={0}; dame!!
    // ll c[i][j]{0}; dame !!
    // ll c[n][l]{};// init with 0
    // std::fill(*c, *c + n*l, 0);
    double x[100] = {0};
    // ==
    double aaa[100]{};
    ll c[n][l]{};// init with 0
    // ==
    REP(i,n){
        REP(j,l){
           c[i][j]=0;
        }
    }

    // allow space, read until \n
    std::getline(std::cin, s);
    cout<<s<<endl;// need endl

    
int calc_digitnum(long long N) {
    int res = 0;
    while (N) {
        ++res;
        N /= 10;
    }
    return res;
}
int calc_digitsum(long long N) {
    int res = 0;
    while (N) {
        //cout<<N%10<<endl;
        res+=N%10;
        N /= 10;
        
    }
    return res;
}

    char ch;
	while((ch = getchar()) != EOF){
	}
    string s;
    int nc[26]={};
    while(getline(cin, s)){

    }
```

<Enter><Ctrl-Z><Enter> to generate EOF in visualcode


```cpp  
// cpp での！！！
// string manipulations
// http://farma-11.hatenablog.com/entry/2018/01/18/094729
    string s,p;
    getline(cin, s);
    getline(cin, p);

    s+=s;
    
    if(s.find(p)!=string::npos){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
//\\\\\\\\\\\\\\\\\\\\\\\\
    char ch;
    int a[256]{};
	while((ch = getchar()) != EOF){
        a[ch]++;
       
	}
     for(int i=97;i<=122;i++)cout<<(char)i<<" : "<<a[i]+a[i-32]<<endl;
    

    int left = a,right = b;
	        while(left < right){// banpei!!
		        swap(s[left++],s[right--]);
	        }

// floating point
int main(){
	double x1,y1,x2,y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	printf("%.8lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    //==
     double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    cout<< std::fixed << std::setprecision(8) <<sqrt((a-c)*(a-c)+(b-d)*(b-d))<<endl;

}


// grid
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




// run-length 
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    // ランレングス圧縮
    // "R"RR"L"LLLLL"R"R"L"LLL div={0,3,9,11,...} 
    // i-th(0-based idx) charater sequence's char count == div[i+1]-div[i]
    vector<int> res(N, 0);
    vector<int> div({0}); // 変わり目をメモ 
    for (int i = 0; i < S.size();) {
        int j = i;
        while (j < N && S[j] == S[i]) ++j;
        div.push_back(j);

        // R と L の個数から、集計
        if (S[i] == 'L') {
            int A = div[div.size()-2] - div[div.size()-3];
            int B = div[div.size()-1] - div[div.size()-2];
            res[i-1] = (A+1)/2 + B/2;
            res[i] = A/2 + (B+1)/2;
        }

        // 更新
        i = j;
    }
    for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
}

// doubling, next[k][i], 2^k step ahead, 二進数展開、K回先の要素を知りたい
#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int main() {
    string S;
    cin >> S;
    int N = S.size();

    // matrix next[k][i]
    vector<vector<int>> next(MAX, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'L') next[0][i] = i-1;
        else next[0][i] = i+1;
    }
    for (int d = 0; d+1 < MAX; ++d) {
        for (int i = 0; i < N; ++i) next[d+1][i] = next[d][next[d][i]];
    }

    vector<int> res(N, 0);
    int K = N*2;
    for (int v = 0; v < N; ++v) {
        int nv = v;
        // 二進数展開
        for (int d = 0; d < MAX; ++d) {
            if (K & (1<<d)) nv = next[d][nv];
        }
        res[nv]++;
    }
    for (int v = 0; v < N; ++v) cout << res[v] << " ";
    cout << endl;
}

// 約数列挙
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


//next_permutation
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{ 1, 2, 3 }; //要素は昇順にソートしておく
    
    for( int i = 0; i < 6; ++i )
    {
        for( auto &x : v ){cout << x << " ";}cout << endl;
        next_permutation( begin( v ), end( v ) ); //次の順列が生成される
    }
    return 0;
}
```



```cpp
// bfs queue 
// https://qiita.com/drken/items/996d80bcae64649a6580
#include <bits/stdc++.h>
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
        G[b].push_back(a);// undirected graph
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

// bfs with grid (rather than node)
// grid repainting 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int h,w;
    cin>>h>>w;
    vector<vector<char>>s(h);
    vector<int>dist(w*h);
    const vector<int> dx = {-1, 0, 1, 0};
    const vector<int> dy = {0, -1, 0, 1};
    int cw=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char x;
            cin>>x;
            s[i].push_back(x);
            if(x=='.')cw++;
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dist[i*w+j]=-1;// not visited
        }
    }

    queue<int>q;
    dist[0]=0;
    q.push(0);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=v%w+dx[i];
            int ny=v/w+dy[i];
            int nv=ny*w+nx;
            if(nx<0||nx>=w||ny<0||ny>=h)continue;
            //if(s[ny][nx]=='#'){cout<<"skiped: "<<s[ny][nx]<<" ("<<nx<<","<<ny<<endl;continue;}
            if(s[ny][nx]=='#')continue;
            if(dist[nv]!=-1)continue;
            dist[nv]=dist[v]+1;
            //cout<<s[ny][nx]<<" ("<<nx<<","<<ny;
            //cout<<"), d:"<<dist[nv]<<endl;
            q.push(nv);
        }
    }

    if(dist[(h-1)*w+(w-1)]==-1){
        cout<<-1<<endl;
    }else{
        cout<<cw-(dist[(h-1)*w+(w-1)]+1)<<endl;
    }
    


    return 0;
}


// dfs stack
// https://algo-logic.info/dfs/
#include <bits/stdc++.h>
using namespace std;
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
    stack<int> st;
    st.emplace(s);  // sから探索する
    seen[s] = true;
    while (st.size() != 0) {   // 深さ優先探索
        int state = st.top();  // 現在の状態
        st.pop();
        for (auto next : G[state]) {
            if (!seen[next]) {  // 未探索の時のみ行う
                seen[next] = true;
                st.emplace(next);  //次の状態をqueueへ格納
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


// tree if(nv==p)continue; with dfs, weighted-edge
// acyclic
// du+dv^2dw==du,v
// #edges == #nodes-1
// D-Ki

// D-Even Relation
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int n;
    cin>>n;
    vector<vector<pair<int,ll>>>g(n); // g[from].push_back({to, weight(from,to)});
    vector<ll>dist(n,-1);// -1 unvisited
    for(int i=0;i<n-1;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        if(w&1)w=1;
        else w=0;
        g[u-1].push_back({v-1,w}); // zero based index
        g[v-1].push_back({u-1,w});// undirected graph
    }

    stack<int>s;
    s.push(0);
    dist[0]=0;
    while(!s.empty()){
        int v=s.top();
        s.pop();
        for(auto nv:g[v]){
            if(dist[nv.first]!=-1)continue;// nv.fist==v
            dist[nv.first]=dist[v]+nv.second;// mark visited
            s.push(nv.first);
        }
    }

    for(int i=0;i<n;i++){
        cout<<(dist[i]%2==0?0:1)<<endl;
    }

    return 0;
}




// binary search
// https://drken1215.hatenablog.com/entry/2020/01/05/154700
// 絶対に f(left)≤Xf(left)≤X を満たす left(0 とかで OK) 
// 絶対に f(right)>Xf(right)>X を満たす rightright (1000000001 とかで OK)
// leftleft は常に f(left)≤Xf(left)≤X を満たし続けながら、
// rightright は常に f(right)>Xf(right)>X を満たし続けながら狭まりつづける
// 結果, 一要素になるまでright-left==1狭まり続ける.
// f(mid)<=X ( f(N)≤Xを満たす最大の正の整数N )
// min's max
// max's min

// buy an integer
#include <bits/stdc++.h>
using namespace std;

auto d(long long N){
    long long res = 0;
    while (N) ++res, N /= 10;
    return res;
}

auto f(long long N, long long A, long long B, long long X) {
    return A * N + B * d(N) > X;
}

int main() {
    long long A, B, X;
    cin >> A >> B >> X;
    // binary search
    long long left = 0, right = 1000000001;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (f(mid, A, B, X)) right = mid;
        else left = mid; // ( f(mid)≤Xを満たす最大の正の整数mid )
    }
    cout << left << endl;
}



// lower_bound(,,x) x 以上の一番左
// upper_bound(,,x) xより大きい一番左
// ll lower_bound(,,x)-a.begin() x未満（より小さい）の個数
// ll n-upper_bound(,,x) xより大きい個数
// ll cnt=upper-lower; xの個数
// upper+cnt x以上の個数
// lower+cnt x以下の個数




// bekkai kosuubunnpu 個数分布　ex. not so diverse
// backet sort desc
// kaku suuji ooi hou kara K shurui toru
```