
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


```cpp
// knapsack
// 何個使ってもいいナップサック問題！！
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

    int h,n;cin>>h>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    // dpi,j:= 前からi個のいくつか使って、モンスターの残りのライフがjの時のコストの最小値
    // 何個使ってもいいナップサック問題！！
    int MAX=10101;
    vector<vector<int>>dp(MAX, vector<int>(MAX,inf));

    dp[0][h]=0;
    for(int i=0;i<=n;i++){
        for(int j=h;j>=0;j--){
            chmin(dp[i][max(0,j-a[i])],dp[i][j]+b[i]);// use i th magic 
            chmin(dp[i+1][j],dp[i][j]);// dont use i th magic anynmore
            // max(0,j-a[i])0以下もゼロにまとめる
        }
    }


    cout<<dp[n][0]<<endl;


    return 0;
 }

```


```cpp
// green tokurina

// jikken for loop toka
// cusum tokaha test case de iter kakuninn

// shakutori hou
条件を満たす連続する区間を探すときに、左端を全探索(es, outer for loop )して、条件を満たす右端を高速に数え上げるというのがある。
左端を全探索すると、総和がK以上である右端であるかどうかは単調性を持つ。

// ver1
// l es
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {

        int n; ll k; cin >> n>>k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        /* 区間の長さの最小値 */
        ll res = 0; // 上界を入れておく

        /* 区間の左端 left で場合分け */
        int right = 0;
        long long sum = 0;
        for (int left = 0; left < n; ++left) {
            /* [left, right) の総和が x 以上となる最小の right を求める */
            while (right < n && sum < k) {
                sum += a[right];
                ++right;
            }

            /* 更新 */
            if (sum < k) break; // これ以上 left を進めてもダメ
            res+=(n-right+1);
            //cout<<left<<", "<<right<<": "<<endl;

            /* left をインクリメントする準備 */
            if (right == left) ++right; // right が left に重なったら right も動かす
            else sum -= a[left]; // left のみがインクリメントされるので sum から a[left] を引く
        }

        cout<<res<<endl;

        return 0;
}

// ver2
// r es
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

vector<pair<char, int>> runLengthEncoding(string s) {
	int n = s.length();
 
	vector<pair<char, int>> res;
	char pre = s[0];
	int cnt = 1;
	rep(i, 1, n) {
		if (pre != s[i]) {
			res.push_back({ pre, cnt });
			pre = s[i];
			cnt = 1;
		}
		else cnt++;
	}
 
	res.push_back({ pre, cnt });
	return res;
}

int main() {

    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<pair<char, int>>p=runLengthEncoding(s);
    //for(auto e:p)cout<<e.first<<", "<<e.second<<endl;

    int res=-1;
    int zero=0;
    int cnt=0;
    int l=0;
    // sharitori hou
    for(int r=0;r<p.size();r++){
        cnt += p[r].second;
		if (p[r].first == '0') zero++;
 
		while (k < zero) {
		    cnt -= p[l].second;
			if (p[l].first == '0') zero--;
			l++;
		}
 
		chmax(res, cnt);
	}

    cout<<res<<endl;

    return 0;
}
```


```cpp

// xor characteristics
// for-loop tokade jikken juuyou!!


```


```cpp
// run length
vector<pair<char, int>> runLengthEncoding(string s) {
	int n = s.length();
 
	vector<pair<char, int>> res;
	char pre = s[0];
	int cnt = 1;
	rep(i, 1, n) {
		if (pre != s[i]) {
			res.push_back({ pre, cnt });
			pre = s[i];
			cnt = 1;
		}
		else cnt++;
	}
 
	res.push_back({ pre, cnt });
	return res;
}

```


```cpp
            //sort(ncnt.begin(),ncnt.end());// by desc, first multiplied by -1 then first by desc second by asc

            // sort first by asc, second by desc
            sort(ncnt.begin(),ncnt.end(),[](auto p1, auto p2) {
                return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
            });// by desc

```


```cpp
// simplify dp
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

    int n;cin>>n;
    vector<int>a(n),b(n);
    for(auto &e:a)cin>>e;
    for(auto &e:b)cin>>e;

    // kubaru dp
    vector<vector<ll>>dp(n+10,vector<ll>(3001,0));
    for(int j=a[0];j<=b[0];j++){
        dp[0][j]=1;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<3001;j++){
            for(int k=0;k<3001;k++){
                if(j<=k&&a[i+1]<=k&&k<=b[i+1]){ // simplify dp by adding constraint-if rather than specific start point in for-loop
                    dp[i+1][k]+=dp[i][j];
                    dp[i+1][k]%=998244353;
                }

            }
        }
    }

    ll res=0;
    for(int j=0;j<3001;j++){
        res+=dp[n-1][j];
        res%=998244353;
    }

    cout<<res<<endl;

    return 0;
}

/*
    vector<vector<ll>>dp(n+10,vector<ll>(n+10,0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++) 
        for(int lst=0;lst<3001;lst++) 
            for(int nxt=lst;nxt<3001;nxt++) {
                if (a[i] <= nxt && nxt <= b[i]) 
                    dp[i + 1][nxt] += dp[i][lst];
            }

    ll res=0;
    for(int j=0;j<3001;j++){
        res+=dp[n][j];
        res%=998244353;
    }

    cout<<res<<endl;

*/

// speed up dp by transforming kubaruDP into morauDP
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


// morau dp,initial value in dp0,0, if-constraint, cusum s0=0, sj is sum of dpi,[0,j), 3001+1 for loop

int main(){

    int n;cin>>n;
    vector<int>a(n),b(n);
    for(auto &e:a)cin>>e;
    for(auto &e:b)cin>>e;

    // morau dp
    vector<vector<ll>>dp(n+1,vector<ll>(3001,0));
    dp[0][0]=1;
    for(int i=1;i<n+1;i++){
        // cusum
        vector<ll>s(3001+1,0);//s[0]=0; sj is sum of dp,[0..j) NOT contain right end!!
        for(int j=0;j<3001+1;j++){
            s[j+1]=s[j]+dp[i-1][j];
            s[j+1]%=998244353;
        }
        for(int j=0;j<3001;j++){
            if(a[i-1]<=j&&j<=b[i-1]){
                dp[i][j]=s[j]+dp[i-1][j];
                dp[i][j]%=998244353;
            }
        }
    }

    ll res=0;
    for(int j=0;j<3001;j++){
        res+=dp[n][j];
        res%=998244353;
    }
    cout<<res<<endl;

    return 0;
}


/*
    // morau dp
    vector<vector<ll>>dp(n+1,vector<ll>(3001,0));
    dp[0][0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<3001;j++){
            for(int k=0;k<3001;k++){
                if(k<=j&&a[i-1]<=j&&j<=b[i-1]){
                    dp[i][j]+=dp[i-1][k];
                    cout<<i<<","<<j<<" += "<<i-1<<","<<k<<endl;
                    cout<<"dp "<<i<<": "<<dp[i][j]<<endl;
                }
            }
            
        }
    }
    
    ll res=0;
    for(int j=0;j<3001;j++){
        res+=dp[n][j];
        res%=998244353;
    }
    cout<<res<<endl;


*/

```


```cpp 
/*
 a1, a2, ..., aN の最大公約数を D とする(D=gcd(a1...an))と、a1, a2, ..., aN は D で割り切れるので M = a1 + a2 + ... + aNも D で割り切れます。(a%D + b%D == (a+b)%D  == M%D) 従って、D は M の約数になります。
また、D が M の約数のとき、a1, a2, ..., aN ≥ D なので M ≥ N × D です。
実は D が M の約数であって M ≥ N ×D を満たすとき、最大公約数が D 以上となるように a1, a2, ..., aN
が構成できます。具体的には、a1 = a2 = ... = aN−1 = D, aN = M − (N − 1) × D とします。このとき、
aN は正整数かつ D の倍数なので各要素の最大公約数は D 以上*1となります。
*/
```

// median no motomekata
// マンハッタン距離の差の総和を最小化するときは中央値を使う         
    int mid;
    if (n % 2 == 1) mid = b[n / 2];
    else mid = (b[n / 2 - 1] + b[n / 2]) / 2;



// memo, rec keisannryou
メモ化再帰（動的計画法）で解く。
「f(cu) := cu円引き出すのに必要な最小の操作回数」
と定義して、メモ化再帰を行う。
状態数はcuが0～Nだけ取りうるのでO(N)
　
遷移であるが、1円の遷移は別に大丈夫。
6の累乗円の遷移はすぐにNを超えてしまうので、O(log6N) (<log2N)くらい(6^p=N, 2^x=N then p<xのはず)
9の累乗円の遷移も同様。
よって、遷移数はO(log6N)となる。
　
これでO(NlogN)なので間に合う。 (遷移数edge*状態数node)



```cpp
// grid dfs

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



int H, W;
string B[50];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
//---------------------------------------------------------------------------------------------------
int vis[55][55];
int dp[55][55];
int check() {
    queue<pair<int, int>> que;
    que.push({ 0, 0 });
    vis[0][0] = 1;
    while (!que.empty()) {
        auto q = que.front(); que.pop();
        int x, y;
        tie(x, y) = q;
 
        if (x == W - 1 and y == H - 1) return dp[y][x];
 
        rep(d, 0, 4) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (0 <= xx and xx < W and 0 <= yy and yy < H) {
                if (B[yy][xx] == '.' and vis[yy][xx] == 0) {
                    vis[yy][xx] = 1;
                    dp[yy][xx] = dp[y][x] + 1;
                    que.push({ xx, yy });
                }
            }
        }
    }
 
    return 0;
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> H >> W;
    rep(y, 0, H) cin >> B[y];
 
    int ans, res = check();
    if (!res) ans = -1;
    else {
        ans = H * W - res - 1;
        rep(y, 0, H) rep(x, 0, W) if (B[y][x] == '#') ans--;
    }
 
    printf("%d\n", ans);
    return 0;
}

```



```cpp
// 
// dfs stack adjacent vector(list)
//https://algo-logic.info/dfs/

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


struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;

int n;
Graph g;//c,s,f
vector<int>c,s,f;


int dfs(int v){
    vector<bool> seen(n, false);  // 既に見たことがある頂点か記録する
    vector<int> dist(n, -1); 
    stack<int> st;
    seen[v] = true;
    dist[v]=0;
    st.emplace(v);  // sから探索する
    while (st.size() != 0) {   // 深さ優先探索
        int state = st.top();  // 現在の状態
        st.pop();
        for (auto e:g[state]) {
            auto next=e.to;
            if (!seen[next]) {  // 未探索の時のみ行う
                seen[next]=true;
                if((dist[state])>=s[state]){
                    // 始発後に到着、次の電車待つ
                    if(dist[state]%f[state]>0){
                        dist[next]=(dist[state]/f[state]+1)*f[state]+c[state];
                    }else{ 
                        dist[next]=(dist[state]/f[state])*f[state]+c[state];
                    }
                }else{ // state駅の始発を待って出発
                    dist[next]=s[state]+c[state];
                }
                st.emplace(next);  //次の状態をqueueへ格納
            }
        }
    }

    return dist[n-1];
}

int main() {
    cin>>n;
    g.resize(n);
    c.resize(n);
    s.resize(n);
    f.resize(n);

    for (int i = 0; i < n-1; i++) {
        cin >>c[i]>>s[i]>>f[i];
        g[i].push_back({i+1});
    }

    for(int i=0;i<n;i++){
        cout<<dfs(i)<<endl;
    }
    
    return 0;
}

```


```cpp
// https://algo-logic.info/dijkstra/
#include <bits/stdc++.h>
using namespace std;
struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;
Graph g;

/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
    g.assign(n);
    vector<ll> dist(10, INF);
    vector<int> prev(10, -1);
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &prev) {
    int N = G.size();
    dis.resize(N, INF);
    prev.resize(N, -1); // 初期化
    priority_queue<P, vector<P>, greater<P>> pq; 
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

/* get_path(prev, t)
    入力：dijkstra で得た prev, ゴール t
    出力： t への最短路のパス
*/
vector<int> get_path(const vector<int> &prev, int t) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}


```