deque は double-ended-queue の略で「デック」と発音される。

deque は vector と同じ動的配列クラスで、末尾だけでなく先頭への要素追加・削除も O(1) と高速なクラスだぞ。



```cpp
// 01 BestFS, grid
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


const int dy[5] = {-2, -1, 0, 1, 2}, dx[5] = {-2, -1, 0, 1, 2};

int main() {
    ll h, w;cin>>h>>w;
    ll a,b,c,d;cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    vector<vector<char>>s(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>s[i][j];
        }
    }

    vector<vector<ll>>dist(h, vector<ll>(w,inf));  // 魔法使った回数
    deque<pair<int,int>>q;
    // q: 移動Aでの幅優先探索用
    // dist: 移動Bでの幅優先探索用
    q.push_back({a,b});
    dist[a][b] = 0;

    // 0-1 BestFS. grid
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop_front();
        for (ll x = 0; x < 5; ++x) {
            for (ll y = 0; y < 5; ++y) {
                // 次の候補地の座標を ni, nj とする
                int ni = i + dy[y], nj = j + dx[x];
                ll d = abs(dy[y]) + abs(dx[x]);
                //cout<<ni<<" "<<nj<<endl;
           
                // フィールドから出たらスルー
                if ( ni<0 || h<=ni || nj<0 || w<=nj )continue;
                // 壁だったらスルー
                if (s[ni][nj] == '#') continue;
           
                // 隣接している場合は cost = 0 で移動可能
                // 左に push
                if (d<=1){
                    if (dist[ni][nj] > dist[i][j]){
                        dist[ni][nj] = dist[i][j];//+0
                        q.push_front({ni,nj});                       
                    }
                }
                // 離れている場合は cost = 1 で移動可能
                // 右に push
                else{
                    if(dist[ni][nj] > dist[i][j]+1){
                        dist[ni][nj] = dist[i][j]+1;
                        q.push_back({ni,nj});
                    }
                }
            }
        }
    }
        
    if (dist[c][d] == inf) {
        cout << -1 << endl;
    } else {
        cout << dist[c][d] << endl;
    }
    return 0;
}

```

平均値が  K 以上
⇔  a-K, b-K, c-K, \dots の平均値が  0 以上
⇔  a-K, b-K, c-K, \dots の総和が  0 以上

転倒数


```cpp
    // fenwick, bit , compress
    // ATTENTION!!
    // Ai<=10^9 -compress-> N<=10^5
    // attention!! add(x), sum(x), x must be x>=1, 
    // compressed array starts from 0 
    // use mod in BIT structure
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

template <class Abel> struct BIT {
    vector<Abel> dat;
    Abel UNITY_SUM = 0;                     // to be set

    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) {
        dat.resize(n + 1);
        for (int i = 0; i < (int)dat.size(); ++i) dat[i] = UNITY_SUM;
    }

    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    /* k-th number (k is 0-indexed) */
    int get(long long k) {
        ++k;
        int res = 0;
        int N = 1; while (N < (int)dat.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)dat.size() && dat[res + i] < k) {
                k = k - dat[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }

    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};


const ll mod = 998244353;

ll modpow(ll x, ll y){
    ll ret = 1;
    while(0 < y){
        if(y & 1){
            ret *= x;
            ret %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return ret;
}

int compress(vector<int> &A){
    std::map<int,int> mem;
    for(auto p: A) mem[p] = 0;
    int sz = 0;
    for(auto &p: mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}

int main(){
    const ll div = modpow(2,mod-2); // 1/2^(i+1) mod p == (2^(p-2))^(i+1)
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    // Ai<=10^9 -compress-> N<=10^5
    // attention!! add(x), sum(x), x must be x>=1, 
    // compressed array starts from 0 
    int n = compress(A);
    BIT<long long> bit(n); 
    ll ans = 0;
    for(int i=0; i<N; i++){
        ans += bit.sum(A[i]+1)*modpow(2,i);
        ans %= mod;
        bit.add(A[i]+1,modpow(div,i+1));
    }
    cout << ans << endl;
    return 0;
}
```


```cpp
                //Bに到達した後に再帰から戻ってくる帰りの部分は
                //丁度最短経路のみ通ってくることになる

                // need to distinguish edge No. then use,..
                // vector<pair<int, int>> E[1010];
#include <bits/stdc++.h>
using namespace std;

// dfs, recur, backtrack, keep edgeNo.

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
int cnt[1010]; // cnti --> # edgei visited 
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

```


```cpp
// dfs, kazoeage, goalに着いた時にカウント
#include <iostream>
using namespace std;
int H, W, A, B, ans = 0;
void dfs(int i, int bit, int A, int B){
    // bit set already tatami is placed @ i[0,HW)
    // row0[0,w)row1[w,2*w)..[,HW)
    if(i == H * W){ans++;return;}//return (void)ans++;// 
    if(bit & 1 << i) return dfs(i + 1, bit, A, B);
    // 正方形
    if(B) dfs(i + 1, bit | 1 << i, A, B - 1);
    // 長方形
    if(A){
        // 右に伸ばす
        if(i % W != W - 1 && ~bit & 1 << (i + 1)) dfs(i + 1, bit | 1 << i | 1 << (i + 1), A - 1, B);
        // 下に伸ばす
        if(i + W < H * W) dfs(i + 1, bit | 1 << i | 1 << (i + W), A - 1, B);
    }
}
int main(){
    cin >> H >> W >> A >> B;

    // 長方形の畳の左上となる場所を決め、そこから右か下かどちらに伸ばす
    // 3(置き方　正方形x1+長方形x2)^16(#grid) O(3^16)
    dfs(0, 0, A, B);
    cout << ans << endl;
}
```