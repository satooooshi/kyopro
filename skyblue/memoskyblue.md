
```cpp
// BIT fenwick tree 1-based

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
};

int main() {

    BIT<int> bit(200000);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int T, X;
        cin >> T >> X;
        if (T == 1) bit.add(X, 1); // insert X
        else {
            int val = bit.get(X - 1); // X is 1-indexed
            cout << val << endl;
            bit.add(val, -1); // delete val
        }
    }

    return 0;
}


```

deque は double-ended-queue の略で「デック」と発音される。

deque は vector と同じ動的配列クラスで、末尾だけでなく先頭への要素追加・削除も O(1) と高速なクラスだぞ。



```cpp
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

