// recursive DP
// traverse from leaf, or post-order traversal

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;

vector<int> edge[100005]; // edge[x][i] node x's i-th child
bool ch[100005] = {0}; // already visited ?
ll dp[100005][2] = {0};

ll solve(int x) {
  ch[x] = 1; // mark as visited
  ll b = 1, w = 1; // black and white
  for(int i = 0; i < edge[x].size(); ++i) {
    if(!ch[edge[x][i]]) solve(edge[x][i]); // not visited yet
    if(dp[edge[x][i]][0] == 0) continue;
    b *= dp[edge[x][i]][1];
    b %= mod;
    w *= (dp[edge[x][i]][0] + dp[edge[x][i]][1]) % mod;
    w %= mod;
  }
  dp[x][0] = b;
  dp[x][1] = w;
  //cout<<"x:"<<x<<endl;
  return (dp[0][0] + dp[0][1]) % mod;
}

int main(){

    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++){ // tree's #edges is #nodes-1
        ll x,y; 
        cin>>x>>y;
        --x;    // 0-based indexing
        --y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    cout<<solve(0)<<endl;
    
    return 0;
}