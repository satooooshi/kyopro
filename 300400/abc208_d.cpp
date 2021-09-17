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


typedef vector<vector<int> > Matrix;

const int INF = inf;
Matrix d; // グラフの距離を格納した2次元配列（隣接行列）
          // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）
ll res=0;
void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++){      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
  for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)
        if(d[j][k]!=INF)res+=d[j][k];
  }
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
    from--;
    to--;
    d[from][to] = cost;
  }
  
  warshall_floyd(n);
  cout<<res<<endl;
  
  return 0;
}