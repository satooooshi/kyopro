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