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


int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    vector<long long> sub(n,1), ans(n); // sub[s] is size()#nodes of subtree, containing s itself
    function<void(int, int, int)> dfs=[&](int i, int p, int d){
        ans[0] += d;
        for(int x : g[i]) if(x != p) {
            dfs(x, i, d+1);
            sub[i] += sub[x];
        }
    }; dfs(0, -1, 0);
    function<void(int, int)> dfs2=[&](int i, int p){
        for(int x : g[i]) if(x != p) {
            // -sub[x]: ある頂点 j が頂点 s の部分木に含まれる場合のans(1) と ans(s) の差分
            // n-sub[x]: ある頂点 j が頂点 s の部分木に含まれない場合のans(1) と ans(s) の差分
            ans[x] = ans[i] - 2 * sub[x] + n;
            dfs2(x, i);
        }
    }; dfs2(0, -1);
    for(long long x : ans) cout << x << endl;

    return 0;
}

