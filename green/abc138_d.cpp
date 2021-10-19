#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int N,Q;
vector<ll>p;
vector<vector<int>>E;
//---------------------------------------------------------------------------------------------------
void dfs(int cu, int pa = -1) {
    
    fore(to, E[cu]) if (to != pa) {
        p[to]+=p[cu];
        dfs(to, cu);
    }
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin>>N>>Q;
    E.resize(N);
    rep(i, 0, N - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    p.assign(N,0);
    rep(i, 0, Q) {
        int a,b;cin>>a>>b;
        a--;
        p[a]+=b;
    }

    dfs(0);
    for(int i=0;i<N;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;

return 0;
}