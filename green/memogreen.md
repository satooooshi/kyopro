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


