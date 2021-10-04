
cusum とか実際に例を通して、idx管理する

```cpp

// min cost flow
// 一定の流量Fを流すときの最小コスト(mx-viで最大コスト)
// 必ずしもすべてのフローを流す必要はない時, graph.add_edge(s, g, mx, mx);

// https://zenn.dev/wapa5pow/articles/practice2-e-e6ce54a9fd90bfb9afbc

// g++-10 practice2_e.cpp -std=c++17 -I /Users/satoshiaikawa/kyoprodev/ac-lib/ac-library

// -10 for bits/stdc++.h
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
const int MOD = 1e9 + 7;

int main() {
  ll mx = 1e9;
  ll n, k;
  cin >> n >> k;
  ll m = 2 * n + 2;
  ll s = 2 * n;
  ll g = s + 1;
  mcf_graph<ll, ll> graph(m);
  for (int i = 0; i < n; i++) {
    graph.add_edge(s, i, k, 0);
    graph.add_edge(n + i, g, k, 0);
  }
  vector<vector<ll>> a(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 最小費用流なので, 大きい値ほど小さくしておく
      cin >> a[i][j];
      a[i][j] = mx - a[i][j];
      graph.add_edge(i, n + j, 1, a[i][j]);
    }
  }
  graph.add_edge(s, g, mx, mx);
  ll ans = 0;
  auto r = graph.flow(s, g, n * k);
  vector<vector<char>> result(n, vector<char>(n, '.'));
  for (auto edge : graph.edges()) {
    if (edge.from == s || edge.to == g || edge.flow == 0) continue;
    int i = edge.from;
    int j = edge.to - n;
    result[i][j] = 'X';
    ans += mx - edge.cost;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j];
    }
    cout << endl;
  }
}


```




```cpp
    vector<int>a(n);
    for (auto& e : a) {
        cin>>e;
    }


    // mex
    #include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main(){


    int n,m;cin>>n>>m;
    vector<int>a(n);
    for (auto& e : a) {
        cin>>e;
    }

    vector<int>cnt(10000000);// 0..

    for(int i=0;i<m;i++){
        cnt[a[i]]++;
    }

    // mex of first [0,m)
    int res=inf;
    for(int x=0;x<10000000;x++){
        if(cnt[x]==0){
            res=min(res,x);
            break;
        }
    }
    //cout<<res<<endl;

    // shakutori-hou
    for(int i=m;i<n;i++){
        cnt[a[i]]++;
        cnt[a[i-m]]--;
        if(cnt[a[i-m]]==0){
            res=min(res,a[i-m]);
            
        }
    }

    cout<<res<<endl;

    return 0;
}
```


```cpp
// manhattan
// 二点の位置関係で絶対値はずす
// https://drken1215.hatenablog.com/entry/2020/10/31/192400

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> x(N), y(N), sum(N), sub(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
        sum[i] = x[i] + y[i];
        sub[i] = x[i] - y[i];
    }
    sort(sum.begin(), sum.end());
    sort(sub.begin(), sub.end());
    cout << max(sum.back() - sum[0], sub.back() - sub[0]) << endl;
}
```


```cpp
// iterate over a set in C++” Code Answer’s
// https://www.codegrepper.com/code-examples/cpp/iterate+over+a+set+in+C%2B%2B


//Given set s
for(auto it: s){
	cout << it << endl;
}

// set::begin/end
#include <iostream>
#include <set>

int main ()
{
  int myints[] = {75,23,65,42,13};
  std::set<int> myset (myints,myints+5);

  std::cout << "myset contains:";
  for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}

```



```cpp
// e peddler
//dp by topo order (<-->) DAG
// topo adj list(vector not matrix)
//　配るDP（親dpiをその子dpjへ配る, adj[i-1].push_back(j-1)）
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main(){

    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n);// nodes 0-indexed
    vector<ll>a(n);
    for(auto &e:a)cin>>e;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x-1].push_back(y-1);
    }

    //dp by topo order (<-->) DAG
    // topo adj list(vector not matrix)
    //　配るDP（親dpiをその子dpjへ配る, adj[i-1].push_back(j-1)）
    vector<ll>dp(n,infl);
    for(int i=0;i<n;i++){
        for(auto j:adj[i]){
            dp[j]=min(dp[j],min(dp[i],a[i]));
        }
    }

    ll res=-infl;
    for(int i=0;i<n;i++){
        res=max(res,a[i]-dp[i]);// dp[i]円で買って、a[i]円で売る
    }
    cout<<res<<endl;
    return 0;
}

```



```cpp
// isprime
// enumerate prime factors(素因数)
// enumerate divisors（約数）
//　
#include <bits/stdc++.h>
using namespace std;

long long GCD(long long x, long long y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

// isprime[n] := is n prime?
// mebius[n] := mebius value of n
// min_factor[n] := the min prime-factor of n
struct Eratos {
    vector<int> primes;
    vector<bool> isprime;
    vector<int> mebius;
    vector<int> min_factor;

    Eratos(int MAX) : primes(),
                      isprime(MAX+1, true),
                      mebius(MAX+1, 1),
                      min_factor(MAX+1, -1) {
        isprime[0] = isprime[1] = false;
        min_factor[0] = 0, min_factor[1] = 1;
        for (int i = 2; i <= MAX; ++i) {
            if (!isprime[i]) continue;
            primes.push_back(i);
            mebius[i] = -1;
            min_factor[i] = i;
            for (int j = i*2; j <= MAX; j += i) {
                isprime[j] = false;
                if ((j / i) % i == 0) mebius[j] = 0;
                else mebius[j] = -mebius[j];
                if (min_factor[j] == -1) min_factor[j] = i;
            }
        }
    }

    // prime factorization
    // 1は素数ではありません, not included in res
    vector<pair<int,int>> prime_factors(int n) {
        vector<pair<int,int> > res;
        while (n != 1) {
            int prime = min_factor[n];
            int exp = 0;
            while (min_factor[n] == prime) {
                ++exp;
                n /= prime;
            }
            res.push_back(make_pair(prime, exp));
        }
        return res;
    }

    // enumerate divisors
    vector<int> divisors(int n) {
        vector<int> res({1});
        auto pf = prime_factors(n);
        for (auto p : pf) {
            int n = (int)res.size();
            for (int i = 0; i < n; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};

const int MAX = 1100000;
string solve(const vector<long long> &a) {
    Eratos er(MAX);
    vector<int> num(MAX, 0);
    for (auto v : a) {
        auto pf = er.prime_factors(v);
        for (auto p : pf) num[p.first]++;
    }
    bool coprime = true;
    for (int i = 0; i < MAX; ++i) if (num[i] > 1) coprime = false;
    if (coprime) return "pairwise coprime";
    long long g = 0;
    for (int i = 0; i < a.size(); ++i) g = GCD(g, a[i]);
    if (g == 1) return "setwise coprime";
    else return "not coprime";
}

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    cout << solve(a) << endl;   
}

```




```cpp
// dfs with grid with two ver. 

// abc151_d
// dfs with grid, queue, string grid
// https://blog.hamayanhamayan.com/entry/2020/01/12/225950
int H, W;
string S[20];
//---------------------------------------------------------------------------------------------------
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
vector<vector<int>> bfs(int sx, int sy) {
    queue<pair<int, int>> que;
    vector<vector<int>> res(H, vector<int>(W, inf));
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    res[sy][sx] = 0;
    vis[sy][sx] = true;
    que.push({ sx, sy });

    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        rep(d, 0, 4) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (0 <= xx and xx < W and 0 <= yy and yy < H) {
                if (S[yy][xx] != '#' and !vis[yy][xx]) {
                    res[yy][xx] = res[y][x] + 1;
                    vis[yy][xx] = true;
                    que.push({xx, yy});
                }
            }
        }
    }

    return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> H >> W;
    rep(y, 0, H) cin >> S[y];
    int ans = 0;
    rep(sx, 0, W) rep(sy, 0, H) if(S[sy][sx] != '#') {
        auto res = bfs(sx, sy);
        rep(x, 0, W) rep(y, 0, H) if (S[y][x] != '#') chmax(ans, res[y][x]);
    }
    cout << ans << endl;
}


// dfs with grid, recursive, char grid
// 
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


using P = pair<int, int>;
int H, W;
vector<vector<char>> maze;  // 迷路の内容を保存する配列
vector<vector<bool>> seen;  // 既に通った場所なのかを記録しておく配列
vector<vector<int>> dist;  // 既に通った場所なのかを記録しておく配列
P s, g;
int RES=-1;
// dfs with recursive
int dx[4] = {1, -1, 0, 0};  // dx,dy は次の探索場所への距離を表す（４方向分）
int dy[4] = {0, 0, 1, -1};
void dfs(P p) {
    for (int i = 0; i < 4; i++) {
        int ny = p.first + dy[i];                              // 次の探索場所の行番号
        int nx = p.second + dx[i];                             // 次の探索場所の列番号
        if (ny < 0 || H <= ny || nx < 0 || W <= nx) continue;  // 迷路の外に出るならスルー
        if (maze[ny][nx] == '#') continue;                     // 障害物があればスルー
        //if (seen[ny][nx]) continue;                            //探索済みならスルー
        if(dist[ny][nx]<=dist[p.first][p.second]+1)continue;
        //seen[p.first][p.second] = true;
        dist[ny][nx]=dist[p.first][p.second]+1;
        dfs(make_pair(ny, nx));
    }
}


int main() {
    cin >> H >> W;
    maze.assign(H, vector<char>(W, '.'));// 0-based
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(maze[i][j]=='#')continue;
            //seen.assign(H, vector<bool>(W, false));
            dist.assign(H, vector<int>(W, inf));
            dist[i][j]=0;
            dfs(make_pair(i, j));

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if(maze[i][j]!='#')chmax(RES,dist[i][j]);
                }    
            }  
            //seen.clear();
            dist.clear();
        }
    }
    cout<<RES<<endl;

    return 0;
}






```cpp
// ある数の末尾に続く0の個数はある数を素因数分解したときのmin(2の個数, 5の個数)となる。
// N! が 5 で割れる回数 b は、

//N  が奇数のとき、0 個
//N が偶数のとき、(N/2)! が何回 5 で割り切れるか

long long b = 0;
while (N) {
    b += N / 5;
    N /= 5;
}

```